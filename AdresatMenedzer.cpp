#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Recipient adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

}

Recipient AdresatMenedzer::podajDaneNowegoAdresata()
{
    Recipient adresat;

    adresat.setId(plikZAdresatami.getIdOstatniegoAdresata() + 1);
    adresat.setIdOfUser(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.setName(AuxiliaryMethods::loadALine());
    adresat.setName(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.getName()));

    cout << "Podaj nazwisko: ";
    adresat.setSurname(AuxiliaryMethods::loadALine());
    adresat.setSurname(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.getSurname()));

    cout << "Podaj numer telefonu: ";
    adresat.setPhoneNumber(AuxiliaryMethods::loadALine());

    cout << "Podaj email: ";
    adresat.setEmail(AuxiliaryMethods::loadALine());

    cout << "Podaj adres: ";
    adresat.setAddress(AuxiliaryMethods::loadALine());

    return adresat;
}


string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}


void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    adresaci = wczytajAdresatowZalogowanegoUzytkownikaZPliku(); 
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Recipient> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Recipient adresat)
{
    cout << endl << "Id:                 " << adresat.getId() << endl;
    cout << "Imie:               " << adresat.getName() << endl;
    cout << "Nazwisko:           " << adresat.getSurname() << endl;
    cout << "Numer telefonu:     " << adresat.getPhoneNumber() << endl;
    cout << "Email:              " << adresat.getEmail() << endl;
    cout << "Adres:              " << adresat.getAddress() << endl;
}


vector <Recipient> AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA); 
    return adresaci;  
}

void AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Recipient>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> getId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = AuxiliaryMethods::loadCharacter();
            if (znak == 't')
            {
                numerLiniiUsuwanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                plikZAdresatami.usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = AuxiliaryMethods::loadIntegerNumber();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    Recipient adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].getId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = AuxiliaryMethods::choseOptionFromEditionMenu();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].setName(AuxiliaryMethods::loadALine());
                adresaci[i].setName(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].getName()));
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].setSurname(AuxiliaryMethods::loadALine());
                adresaci[i].setSurname(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].getSurname()));
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].setPhoneNumber(AuxiliaryMethods::loadALine());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].setEmail(AuxiliaryMethods::loadALine());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].setAddress(AuxiliaryMethods::loadALine());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Recipient adresat, int idEdytowanegoAdresata)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    plikZAdresatami.edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = AuxiliaryMethods::loadALine();
        imiePoszukiwanegoAdresata = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Recipient>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> getName() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        AuxiliaryMethods::displayNumberOfSearchedRecipients(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = AuxiliaryMethods::loadALine();
        nazwiskoPoszukiwanegoAdresata = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Recipient>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> getSurname() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        AuxiliaryMethods::displayNumberOfSearchedRecipients(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}
