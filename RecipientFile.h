#ifndef RECIPIENTFILE_H
#define RECIPIENTFILE_H
#include<iostream>
#include<vector>
#include<fstream>

#include "Recipient.h"
#include "AuxiliaryMethods.h"

using namespace std; 

class RecipientFile
{
    int idOfLastRecipient;
    const string FILE_NAME_WITH_RECIPIENTS; 

    int getUserIdFromDataSeparetedByVerticalBars(string dataOfOneRecipientSeparetedByVerticalBars); 
    Recipient getDataOfRecipient(string dataOfRecipientSeparetedByVerticalBars); 
    int getRecipientIDFromDataSeparatedByVerticalBars(string dataOfOneRecipientSeparetedByVerticalBars); 
    void deleteFile(string fileNameWithExtention); 
    void changeNameOfFile(string oldName, string newName); 
    
public: 
    RecipientFile(string nameOfFileWIthRecipients): FILE_NAME_WITH_RECIPIENTS(nameOfFileWIthRecipients)
    {
        idOfLastRecipient = 1; 
    } 

    vector<Recipient> loadLoggedUserRecipientsFromFile(int idOfLoggedUser);
    void addRecipientToFile(Recipient recipient);
    int getIdOfLastRecipient(); 
    int returnRecipientLineNumber(int recipientId); 
    void deleteChosenLineInFile(int numberOfDeletedLine); 
    string replaceRecipientDataIntoLineWithDataSeparatedByVerticalBars(Recipient recipient);
    void editChosenLineInFile(int numberOFEditedLine, string lineWithRecipientDataSeparatedByVerticalBars); 
};

#endif