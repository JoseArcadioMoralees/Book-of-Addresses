#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.setId(plikZAdresatami.getIdOstatniegoAdresata() + 1);
    adresat.setIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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


vector <Adresat> AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
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

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> getId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
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
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
