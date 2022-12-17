#include <iostream>
#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.registerAnUser(); 
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.showAllUsers(); 
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.loggingAnUser();
    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.getIdOfLoggedUser()); 
}

void KsiazkaAdresowa::zmianaHasla()
{
    uzytkownikMenedzer.changePasswordOfLoggedUser(); 
}

int KsiazkaAdresowa::getIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.getIdOfLoggedUser();
}

void KsiazkaAdresowa::setIdZalogowanegoUzytkownika(int IDZALOGOWANEGOUZYTKOWNIKA)
{
    uzytkownikMenedzer.setIdOfLoggedUser(IDZALOGOWANEGOUZYTKOWNIKA);
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
