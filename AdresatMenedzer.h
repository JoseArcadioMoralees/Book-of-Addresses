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
    bool czyAbyPlikJestPusty(fstream &plikTekstowy);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);  
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void wyswietlDaneAdresata(Adresat adresat); 

    public: 
    int idOstatniegoAdresata;
    AdresatMenedzer(); 
    void dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata); 
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata); 
    void dopiszAdresataDoPliku(Adresat adresat); 
    void wyswietlWszystkichAdresatow(vector <Adresat> &adresaci); 
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};

#endif