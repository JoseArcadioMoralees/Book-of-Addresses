#include <iostream>
#include "AddressBook.h"
#include "RecipientFile.h"

using namespace std;

int main () 
{
    AddressBook addressBook("Users.txt", "Recipients.txt");

    while (true)
    {
        char option; 
        if (addressBook.getIdOfLoggedUser() == 0)
        {
            option = AuxiliaryMethods::choseOptionFromMainMenu();

            switch (option)
            {
            case '1':
                addressBook.registerAnUser();
                break;
            case '2':
                addressBook.loggingAnUser();
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
            option = AuxiliaryMethods::choseOptionFromUserMenu();

            switch (option)
            {
            case '1':
                addressBook.addRecipient(); 
                break;
            case '2':
                addressBook.searchRecipientByName(); 
                break;
            case '3':
                addressBook.searchRecipientBySurname(); 
                break;
            case '4':
                addressBook.shawAllRecipients(); 
                break;
            case '5':
                addressBook.deleteRecipient(); 
                break;
            case '6':
                addressBook.editRecipient(); 
                break;
            case '7':
                addressBook.changePasswordOfLoggedUser();
                break;
            case '8':
                addressBook.LogOutAnUser();
                break;
            }
        }
    }
    return 0; 
}
