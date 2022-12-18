#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H
#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include "Recipient.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"
#include "RecipientFile.h"

using namespace std; 

class AdresatMenedzer
{ 
    vector <Recipient> adresaci;  
    RecipientFile plikZAdresatami;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);  
    void wyswietlDaneAdresata(Recipient adresat); 
    int podajIdWybranegoAdresata(); 
    void zaktualizujDaneWybranegoAdresata(Recipient adresat, int idEdytowanegoAdresata); 
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public: 
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) 
    : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) 
    {
       adresaci = wczytajAdresatowZalogowanegoUzytkownikaZPliku(); 
    }     
    
    void dodajAdresata(); 
    Recipient podajDaneNowegoAdresata();  
    void wyswietlWszystkichAdresatow(); 
    vector <Recipient> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void usunAdresata(); 
    void edytujAdresata(); 
    void wyszukajAdresatowPoImieniu(); 
    void wyszukajAdresatowPoNazwisku(); 
};

#endif