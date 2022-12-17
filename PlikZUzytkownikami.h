#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H
#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
using namespace std;

class PlikZUzytkownikami
{
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI; 
    User pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public: 
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami){}; 
    
    void dopiszUzytkownikaDoPliku(User uzytkownik);
    vector <User> wczytajUzytkownikowZPliku(); 
    string pobierzNazwaPlikuZUzytkownikami(); 
    static string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User uzytkownik);
    
    
};

#endif