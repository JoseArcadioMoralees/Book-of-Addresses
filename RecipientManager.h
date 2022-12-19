#ifndef RECIPIENTMANAGER_H
#define RECIPIENTMANAGER_H
#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include "Recipient.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"
#include "RecipientFile.h"

using namespace std; 

class RecipientManager
{ 
    vector <Recipient> recipients;  
    RecipientFile recipientFile;
    string replaceFirstLetterToUppercaseAOthersToLowercase(string tekst);  
    void shawRecipientData(Recipient recipient); 
    int getTheIdOfTheRecipient(); 
    void updateDetailsOfSelectedRecipient(Recipient recipient, int idOfEditedREcipient); 
    const int ID_OF_LOGGED_USER;

public: 
    RecipientManager(string nameOfFileWithRecipients, int idOfLoggedUser) 
    : recipientFile(nameOfFileWithRecipients), ID_OF_LOGGED_USER(idOfLoggedUser) 
    {
       recipients = loadLoggedUserRecipientsFromFile(); 
    }     
    
    void addRecipient(); 
    Recipient setDataOfTheNewRecipient();  
    void shawAllRecipients(); 
    vector <Recipient> loadLoggedUserRecipientsFromFile();
    void deleteRecipient(); 
    void editRecipient(); 
    void searchRecipientByName(); 
    void searchRecipientBySurname(); 
};

#endif