#include <iostream>
#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika(); 
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow(); 
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.getIdZalogowanegoUzytkownika()); 
}

void KsiazkaAdresowa::zmianaHasla()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(); 
}

int KsiazkaAdresowa::getIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.getIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::setIdZalogowanegoUzytkownika(int IDZALOGOWANEGOUZYTKOWNIKA)
{
    uzytkownikMenedzer.setIdZalogowanegoUzytkownika(IDZALOGOWANEGOUZYTKOWNIKA);
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow(); 
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    setIdZalogowanegoUzytkownika(0);
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->edytujAdresata(); 
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer->wyszukajAdresatowPoImieniu(); 
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer->wyszukajAdresatowPoNazwisku(); 
}
