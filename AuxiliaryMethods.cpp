#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadALine()
{
    string entry = "";
    cin.clear();  
    getline(cin, entry);
    return entry;
}

char AuxiliaryMethods::choseOptionFromMainMenu()
{
    char option;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    option = loadCharacter();

    return option;
}

char AuxiliaryMethods::loadCharacter()
{
    cin.clear();
    string entry = "";
    char character  = {0};
    while (true)
    { 
        cin.sync();
        getline(cin, entry);
        if (entry.length() == 1)
        {
            character = entry[0];
            cin.clear();
            break;
        } else
        {
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
    }
    return character;
}

char AuxiliaryMethods::choseOptionFromUserMenu()
{
    char option;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    option = AuxiliaryMethods::loadCharacter();

    return option;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::loadNumber(string text, int positionOfCharacter)
{
    string number = "";
    while(isdigit(text[positionOfCharacter]) == true)
    {
        number += text[positionOfCharacter];
        positionOfCharacter ++;
    }
    return number;
}

int AuxiliaryMethods::loadIntegerNumber()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

char AuxiliaryMethods::choseOptionFromEditionMenu()
{
    char option;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    option = loadCharacter();

    return option;
}

void AuxiliaryMethods::displayNumberOfSearchedRecipients(int numberOfRecipients)
{
    if (numberOfRecipients == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << numberOfRecipients << endl << endl;
}

bool AuxiliaryMethods::ifFileIsEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}