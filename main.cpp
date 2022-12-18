#include <iostream>
#include "KsiazkaAdresowa.h"
#include "RecipientFile.h"

using namespace std;

int main () 
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        char wybor; 
        if (ksiazkaAdresowa.getIdZalogowanegoUzytkownika() == 0)
        {
            wybor = AuxiliaryMethods::choseOptionFromMainMenu();

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
            wybor = AuxiliaryMethods::choseOptionFromUserMenu();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata(); 
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu(); 
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku(); 
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow(); 
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata(); 
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata(); 
                break;
            case '7':
                ksiazkaAdresowa.zmianaHasla();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0; 
}
