#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H
#include<iostream>
#include<vector>
#include<fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikZUzytkownikami
{
    string nazwaPlikuZUzytkownikami; 
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    fstream plikTekstowy;

    public: 
    PlikZUzytkownikami(); 
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    
    
};

#endif