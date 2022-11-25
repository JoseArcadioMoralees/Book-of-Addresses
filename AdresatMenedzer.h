#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H
#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std; 

class AdresatMenedzer
{ 
    vector <Adresat> adresaci;  
    PlikZAdresatami plikZAdresatami;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);  
    void wyswietlDaneAdresata(Adresat adresat); 
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public: 
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) 
    : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) 
    {}     
    
    void dodajAdresata(); 
    Adresat podajDaneNowegoAdresata();  
    void wyswietlWszystkichAdresatow(); 
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif