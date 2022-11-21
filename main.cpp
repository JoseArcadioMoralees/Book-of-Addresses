#include <iostream>
#include "KsiazkaAdresowa.h"
#include "PlikZAdresatami.h"

using namespace std;

int main () 
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

    while (true)
    {
        char wybor; 
        if (ksiazkaAdresowa.getIdZalogowanegoUzytkownika() == 0)
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata(); 
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow(); 
                break;
            case '7':
                ksiazkaAdresowa.zmianaHasla();
                break;
            case '8':
                ksiazkaAdresowa.setIdZalogowanegoUzytkownika(0);
                break;
            }
        }
    }
    return 0; 
}
