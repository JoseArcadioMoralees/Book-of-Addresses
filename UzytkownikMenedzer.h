#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <User> uzytkownicy;
    FileWithUsers plikZUzytkownikami; 
    User podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) 
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.loadUsersFromFile();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow(); 
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku(); 
    int getIdZalogowanegoUzytkownika();
    void setIdZalogowanegoUzytkownika(int);
};

#endif