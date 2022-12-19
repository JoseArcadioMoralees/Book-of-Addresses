#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <vector>

#include "UsersManager.h"
#include "RecipientManager.h"
using namespace std;

class AddressBook
{
    UsersManager usersManager; 
    RecipientManager *recipientManager; 
    int idOfLoggedUser = getIdOfLoggedUser(); 
    const string NAME_OF_FILE_WITH_RECIPIENT; 
    
public:  
    AddressBook(string nameOfFileWithUsers, string nameOfFileWithRecipients) 
    : usersManager(nameOfFileWithUsers),  NAME_OF_FILE_WITH_RECIPIENT(nameOfFileWithRecipients)
    {
            recipientManager = NULL;
    }
    ~AddressBook()
    {
        delete recipientManager;
        recipientManager = NULL; 
    }
    
    void registerAnUser(); 
    void showAllUsers(); 
    void loggingAnUser();
    void changePasswordOfLoggedUser();
    int getIdOfLoggedUser(); 
    void setIdOfLoggedUser(int);
    void addRecipient(); 
    void shawAllRecipients();
    void LogOutAnUser(); 
    void deleteRecipient();
    void editRecipient(); 
    void searchRecipientByName(); 
    void searchRecipientBySurname(); 
}; 

#endif