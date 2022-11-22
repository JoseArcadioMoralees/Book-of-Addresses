#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <vector>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer; 
    AdresatMenedzer adresatMenedzer; 
    int idZalogowanegoUzytkownika = getIdZalogowanegoUzytkownika(); 
    
public:  
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) 
        {uzytkownikMenedzer.wczytajUzytkownikowZPliku();}; 
    
    void rejestracjaUzytkownika(); 
    void wypiszWszystkichUzytkownikow(); 
    void logowanieUzytkownika();
    void zmianaHasla();
    int getIdZalogowanegoUzytkownika(); 
    void setIdZalogowanegoUzytkownika(int);
    void dodajAdresata(); 
    void wyswietlWszystkichAdresatow();
}; 

#endif