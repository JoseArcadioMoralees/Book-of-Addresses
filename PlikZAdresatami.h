#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include<iostream>
#include<vector>
#include<fstream>

#include "Recipient.h"
#include "AuxiliaryMethods.h"

using namespace std; 

class PlikZAdresatami
{
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI; 

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); 
    Recipient pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami); 
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami); 
    void usunPlik(string nazwaPlikuZRozszerzeniem); 
    void zmienNazwePliku(string staraNazwa, string nowaNazwa); 
    
public: 
    PlikZAdresatami(string nazwaPlikuZAdresatami): NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 1; 
    } 

    vector<Recipient> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Recipient adresat);
    int getIdOstatniegoAdresata(); 
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata); 
    void usunWybranaLinieWPliku(int numerUsuwanejLinii); 
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Recipient adresat);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami); 
};

#endif