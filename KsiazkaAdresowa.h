#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <vector>

#include "UzytkownikMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer; 
    public:  
    
    void rejestracjaUzytkownika(); 
    void wypiszWszystkichUzytkownikow(); 
}; 

#endif