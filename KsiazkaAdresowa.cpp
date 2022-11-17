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
    adresaci = adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
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
    adresatMenedzer.dodajAdresata(adresaci, uzytkownikMenedzer.getIdZalogowanegoUzytkownika(), adresatMenedzer.idOstatniegoAdresata);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow(adresaci); 
}
