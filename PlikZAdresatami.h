#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include<iostream>
#include<vector>
#include<fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std; 

class PlikZAdresatami
{
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); 
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami); 
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); 
    public: 
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};

#endif