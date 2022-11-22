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
    PlikZAdresatami plikZAdresatami; 
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika; 
    int idOstatniegoAdresata;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);  
    void wyswietlDaneAdresata(Adresat adresat); 

public: 
    AdresatMenedzer(); 
    
    void dodajAdresata(int idZalogowanegoUzytkownika); 
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);  
    void wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika); 
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};

#endif