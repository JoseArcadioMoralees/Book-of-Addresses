#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H
#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikZUzytkownikami
{
    static bool czyPlikJestPusty();
    const string nazwaPlikuZUzytkownikami; 
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

    public: 
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI){}; 
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku(); 
    string pobierzNazwaPlikuZUzytkownikami(); 
    static string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    
    
};

#endif