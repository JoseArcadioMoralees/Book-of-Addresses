#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H
#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include "Adresat.h"
#include "AuxiliaryMethods.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std; 

class AdresatMenedzer
{ 
    vector <Adresat> adresaci;  
    PlikZAdresatami plikZAdresatami;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);  
    void wyswietlDaneAdresata(Adresat adresat); 
    int podajIdWybranegoAdresata(); 
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata); 
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public: 
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) 
    : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) 
    {
       adresaci = wczytajAdresatowZalogowanegoUzytkownikaZPliku(); 
    }     
    
    void dodajAdresata(); 
    Adresat podajDaneNowegoAdresata();  
    void wyswietlWszystkichAdresatow(); 
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void usunAdresata(); 
    void edytujAdresata(); 
    void wyszukajAdresatowPoImieniu(); 
    void wyszukajAdresatowPoNazwisku(); 
};

#endif