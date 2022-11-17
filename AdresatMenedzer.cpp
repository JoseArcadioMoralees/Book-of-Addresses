#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer()
{
    idOstatniegoAdresata = 0; 
}

void AdresatMenedzer::dodajAdresata(vector <Adresat> &adresaci,int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    dopiszAdresataDoPliku(adresat);

    ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    adresat.setId(++idOstatniegoAdresata);
    adresat.setIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.setImie(MetodyPomocnicze::wczytajLinie());
    adresat.setImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.getImie()));

    cout << "Podaj nazwisko: ";
    adresat.setNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.setNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.getNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.setNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.setEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.setAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::dopiszAdresataDoPliku(Adresat adresat)
{
    string nazwaPlikuZAdresatami = "Adresaci.txt"; 
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyAbyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

bool AdresatMenedzer::czyAbyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
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

string AdresatMenedzer::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.getId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.getIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.getImie() + '|';
    liniaZDanymiAdresata += adresat.getNazwisko() + '|';
    liniaZDanymiAdresata += adresat.getNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.getEmail() + '|';
    liniaZDanymiAdresata += adresat.getAdres() + '|';

    return liniaZDanymiAdresata;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow(vector <Adresat> &adresaci)
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
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

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.getId() << endl;
    cout << "Imie:               " << adresat.getImie() << endl;
    cout << "Nazwisko:           " << adresat.getNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.getNumerTelefonu() << endl;
    cout << "Email:              " << adresat.getEmail() << endl;
    cout << "Adres:              " << adresat.getAdres() << endl;
}


vector <Adresat> AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    return adresaci;  
}
