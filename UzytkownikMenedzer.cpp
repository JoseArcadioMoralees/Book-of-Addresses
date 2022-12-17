#include"UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    User uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl
         << "Konto zalozono pomyslnie" << endl
         << endl;
    system("pause");
}

User UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    User uzytkownik;
    uzytkownik.setId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin.sync(); 
        cin >> login;
        uzytkownik.setLogin(login);
    } while (czyIstniejeLogin(uzytkownik.getLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.setPassword(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().getId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].getLogin() == login)
        {
            cout << endl
                 << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].getId() << endl; 
        cout << uzytkownicy[i].getLogin() << endl; 
        cout << uzytkownicy[i].getPassword() << endl; 
    }
}


void UzytkownikMenedzer::logowanieUzytkownika()
{
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadALine();

    vector <User>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = AuxiliaryMethods::loadALine();

                if (itr -> getPassword() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = AuxiliaryMethods::loadALine();

    for (vector <User>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> getId() == idZalogowanegoUzytkownika)
        {
            itr -> setPassword(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    zapiszWszystkichUzytkownikowDoPliku();
}

void UzytkownikMenedzer::zapiszWszystkichUzytkownikowDoPliku()
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector <User>::iterator itrKoniec = --uzytkownicy.end();
    string nazwaPlikuZUzytkownikami = plikZUzytkownikami.pobierzNazwaPlikuZUzytkownikami();

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <User>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = plikZUzytkownikami.zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPlikuZUzytkownikami << endl;
    }
    plikTekstowy.close();
}

int UzytkownikMenedzer::getIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika; 
}

void UzytkownikMenedzer::setIdZalogowanegoUzytkownika(int IDZALOGOWANEGOUZYTKOWNIKA)
{
    idZalogowanegoUzytkownika = IDZALOGOWANEGOUZYTKOWNIKA; 
}
