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
    adresatMenedzer.dodajAdresata(uzytkownikMenedzer.getIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow(uzytkownikMenedzer.getIdZalogowanegoUzytkownika()); 
}
