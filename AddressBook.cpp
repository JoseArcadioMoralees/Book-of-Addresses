#include <iostream>
#include "AddressBook.h"

void AddressBook::registerAnUser()
{
    usersManager.registerAnUser(); 
}

void AddressBook::showAllUsers()
{
    usersManager.showAllUsers(); 
}

void AddressBook::loggingAnUser()
{
    usersManager.loggingAnUser();
    recipientManager = new RecipientManager(NAME_OF_FILE_WITH_RECIPIENT, usersManager.getIdOfLoggedUser()); 
}

void AddressBook::changePasswordOfLoggedUser()
{
    usersManager.changePasswordOfLoggedUser(); 
}

int AddressBook::getIdOfLoggedUser()
{
    return usersManager.getIdOfLoggedUser();
}

void AddressBook::setIdOfLoggedUser(int IDZALOGOWANEGOUZYTKOWNIKA)
{
    usersManager.setIdOfLoggedUser(IDZALOGOWANEGOUZYTKOWNIKA);
}

void AddressBook::addRecipient()
{
    recipientManager->addRecipient();
}

void AddressBook::shawAllRecipients()
{
    recipientManager->shawAllRecipients(); 
}

void AddressBook::LogOutAnUser()
{
    setIdOfLoggedUser(0);
    delete recipientManager;
    recipientManager = NULL;
}

void AddressBook::deleteRecipient()
{
    recipientManager->deleteRecipient();
}

void AddressBook::editRecipient()
{
    recipientManager->editRecipient(); 
}

void AddressBook::searchRecipientByName()
{
    recipientManager->searchRecipientByName(); 
}

void AddressBook::searchRecipientBySurname()
{
    recipientManager->searchRecipientBySurname(); 
}
