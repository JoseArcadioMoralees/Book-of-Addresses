#include <iostream>
#include "KsiazkaAdresowa.h"


using namespace std;

int main ()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt"); 
    // ksiazkaAdresowa.wczytajUzytkownikowZPliku();  
    // ksiazkaAdresowa.rejestracjaUzytkownika(); 
    // ksiazkaAdresowa.rejestracjaUzytkownika();
    // ksiazkaAdresowa.wypiszWszystkichUzytkownikow(); 
    // ksiazkaAdresowa.rejestracjaUzytkownika(); 
    // ksiazkaAdresowa.rejestracjaUzytkownika();
    // ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika(); 
    ksiazkaAdresowa.zmianaHasla(); 

    return 0; 
}
