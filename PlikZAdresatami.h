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
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI; 

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); 
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami); 
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); 
    bool czyAbyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    
public: 
    PlikZAdresatami(string nazwaPlikuZAdresatami): NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;  
    } 

    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    int getIdOstatniegoAdresata(); 

};

#endif