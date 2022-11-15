#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <vector>

#include "UzytkownikMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer; 
    public:  
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {uzytkownikMenedzer.wczytajUzytkownikowZPliku();}; 
    void rejestracjaUzytkownika(); 
    void wypiszWszystkichUzytkownikow(); 
    void logowanieUzytkownika();
    void zmianaHasla();

}; 

#endif