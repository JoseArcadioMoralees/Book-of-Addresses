#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <vector>

#include "UsersManager.h"
#include "AdresatMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UsersManager uzytkownikMenedzer; 
    AdresatMenedzer *adresatMenedzer; 
    int idZalogowanegoUzytkownika = getIdZalogowanegoUzytkownika(); 
    const string NAZWA_PLIKU_Z_ADRESATAMI; 
    
public:  
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) 
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),  NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
            adresatMenedzer = NULL;
    }
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL; 
    }
    
    void rejestracjaUzytkownika(); 
    void wypiszWszystkichUzytkownikow(); 
    void logowanieUzytkownika();
    void zmianaHasla();
    int getIdZalogowanegoUzytkownika(); 
    void setIdZalogowanegoUzytkownika(int);
    void dodajAdresata(); 
    void wyswietlWszystkichAdresatow();
    void wylogowanieUzytkownika(); 
    void usunAdresata();
    void edytujAdresata(); 
    void wyszukajAdresatowPoImieniu(); 
    void wyszukajAdresatowPoNazwisku(); 
}; 

#endif