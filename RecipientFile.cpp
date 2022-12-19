#include "RecipientFile.h"


vector<Recipient> RecipientFile::loadLoggedUserRecipientsFromFile(int idOfLoggedUser)
{
    vector <Recipient> recipients; 
    Recipient recipient;
    string DataforOneRecipientSeparatedbyVerticalBars = "";
    string LastRecipientDataInFile = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, DataforOneRecipientSeparatedbyVerticalBars))
        {
            if(idOfLoggedUser == getUserIdFromDataSeparetedByVerticalBars(DataforOneRecipientSeparatedbyVerticalBars))
            {
                recipient = getDataOfRecipient(DataforOneRecipientSeparatedbyVerticalBars);
                recipients.push_back(recipient);
            }
        }
        LastRecipientDataInFile = DataforOneRecipientSeparatedbyVerticalBars;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    textFile.close();

    if (LastRecipientDataInFile != "")
    {
        idOfLastRecipient = getRecipientIDFromDataSeparatedByVerticalBars(LastRecipientDataInFile);
        return recipients;
    } else
    {
        idOfLastRecipient = 0; 
        return recipients = {}; 
    }
}

int RecipientFile::getUserIdFromDataSeparetedByVerticalBars(string dataOfOneRecipientSeparetedByVerticalBars)
{
    int positionOfStartOFRecipientId = dataOfOneRecipientSeparetedByVerticalBars.find_first_of('|') + 1;
    int UsersId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::loadNumber(dataOfOneRecipientSeparetedByVerticalBars, positionOfStartOFRecipientId));

    return UsersId;
}

Recipient RecipientFile::getDataOfRecipient(string dataOfRecipientSeparetedByVerticalBars)
{
    Recipient recipient;
    string singleRecipientData = "";
    int numberOfSingleRecipientData = 1;

    for (unsigned int characterPosition = 0; characterPosition < dataOfRecipientSeparetedByVerticalBars.length(); characterPosition++)
    {
        if (dataOfRecipientSeparetedByVerticalBars[characterPosition] != '|')
        {
            singleRecipientData += dataOfRecipientSeparetedByVerticalBars[characterPosition];
        }
        else
        {
            switch(numberOfSingleRecipientData)
            {
            case 1:
                recipient.setId(atoi(singleRecipientData.c_str()));
                break;
            case 2:
                recipient.setIdOfUser(atoi(singleRecipientData.c_str()));
                break;
            case 3:
                recipient.setName(singleRecipientData);
                break;
            case 4:
                recipient.setSurname(singleRecipientData);
                break;
            case 5:
                recipient.setPhoneNumber(singleRecipientData);
                break;
            case 6:
                recipient.setEmail(singleRecipientData);
                break;
            case 7:
                recipient.setAddress(singleRecipientData);
                break;
            }
            singleRecipientData = "";
            numberOfSingleRecipientData++;
        }
    }
    return recipient;
}
int RecipientFile::getRecipientIDFromDataSeparatedByVerticalBars(string dataOfOneRecipientSeparetedByVerticalBars)
{
    int positionOfStartOFRecipientId = 0;
    int recipientId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::loadNumber(dataOfOneRecipientSeparetedByVerticalBars, positionOfStartOFRecipientId));
    return recipientId;
}

void RecipientFile::addRecipientToFile(Recipient recipient)
{ 
    string lineWithRecipientData = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithRecipientData = replaceRecipientDataIntoLineWithDataSeparatedByVerticalBars(recipient);

        if (AuxiliaryMethods::ifFileIsEmpty(textFile) == true)
        {
            textFile << lineWithRecipientData;
        }
        else
        {
            textFile << endl << lineWithRecipientData ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    textFile.close();
    system("pause");
}


string RecipientFile::replaceRecipientDataIntoLineWithDataSeparatedByVerticalBars(Recipient recipient)
{
    string lineWithRecipientData = "";

    lineWithRecipientData += AuxiliaryMethods::convertIntToString(recipient.getId()) + '|';
    lineWithRecipientData += AuxiliaryMethods::convertIntToString(recipient.getIdOfUser()) + '|';
    lineWithRecipientData += recipient.getName() + '|';
    lineWithRecipientData += recipient.getSurname() + '|';
    lineWithRecipientData += recipient.getPhoneNumber() + '|';
    lineWithRecipientData += recipient.getEmail() + '|';
    lineWithRecipientData += recipient.getAddress() + '|';

    return lineWithRecipientData;
}

int RecipientFile::getIdOfLastRecipient()
{
    return idOfLastRecipient; 
}

int RecipientFile::returnRecipientLineNumber(int recipientId)
{
    bool ifRecipientExists = false;
    int numberOfLineInTextFile = 1;
    string DataForOneRecipientSeparatedbyVerticalBars = "";
    fstream textFile;
    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::in);

    if (textFile.good() == true && recipientId != 0)
    {
        while(getline(textFile, DataForOneRecipientSeparatedbyVerticalBars))
        {
            if(recipientId == getRecipientIDFromDataSeparatedByVerticalBars(DataForOneRecipientSeparatedbyVerticalBars))
            {
                ifRecipientExists = true;
                textFile.close();
                return numberOfLineInTextFile;
            }
            else
                numberOfLineInTextFile++;
        }
        if (ifRecipientExists == false)
        {
            textFile.close();
            return 0;
        }
    }
    return 0;
}

void RecipientFile::deleteChosenLineInFile(int numberOfDeletedLine)
{
    fstream readTextFile, temporaryTextFile;
    string loadedLine = "";
    int numberOfLoadedLine = 1;
    string temporaryFileNameWithRecipients = "Tymczasowa_nazwa"; 

    readTextFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::in);
    temporaryTextFile.open(temporaryFileNameWithRecipients.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true && numberOfDeletedLine != 0)
    {
        while (getline(readTextFile, loadedLine))
        {
            if (numberOfLoadedLine == numberOfDeletedLine) {}
            else if (numberOfLoadedLine == 1 && numberOfLoadedLine != numberOfDeletedLine)
                temporaryTextFile << loadedLine;
            else if (numberOfLoadedLine == 2 && numberOfDeletedLine == 1)
                temporaryTextFile << loadedLine;
            else if (numberOfLoadedLine > 2 && numberOfDeletedLine == 1)
                temporaryTextFile << endl << loadedLine;
            else if (numberOfLoadedLine > 1 && numberOfDeletedLine != 1)
                temporaryTextFile << endl << loadedLine;
            numberOfLoadedLine++;
        }
        readTextFile.close();
        temporaryTextFile.close();

        deleteFile(NAME_OF_FILE_WITH_USERS);
        changeNameOfFile(temporaryFileNameWithRecipients, NAME_OF_FILE_WITH_USERS);
    }
}

void RecipientFile::deleteFile(string fileNameWithExtention)
{
    if (remove(fileNameWithExtention.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << fileNameWithExtention << endl;
}

void RecipientFile::changeNameOfFile(string oldName, string newName)
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << oldName << endl;
}

void RecipientFile::editChosenLineInFile(int numberOFEditedLine, string lineWithRecipientDataSeparatedByVerticalBars)
{
    fstream readTextFile, temporaryTextFile;
    string loadedLine = "";
    int numberOfLoadedLine = 1;
    string temporaryTextFileName = "Tymczasowa_nazwa"; 

    readTextFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::in);
    temporaryTextFile.open(temporaryTextFileName.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true)
    {
        while (getline(readTextFile, loadedLine))
        {
            if (numberOfLoadedLine == numberOFEditedLine)
            {
                if (numberOfLoadedLine == 1)
                    temporaryTextFile << lineWithRecipientDataSeparatedByVerticalBars;
                else if (numberOfLoadedLine > 1)
                    temporaryTextFile << endl << lineWithRecipientDataSeparatedByVerticalBars;
            }
            else
            {
                if (numberOfLoadedLine == 1)
                    temporaryTextFile << loadedLine;
                else if (numberOfLoadedLine > 1)
                    temporaryTextFile << endl << loadedLine;
            }
            numberOfLoadedLine++;
        }
        readTextFile.close();
        temporaryTextFile.close();

        deleteFile(NAME_OF_FILE_WITH_USERS);
        changeNameOfFile(temporaryTextFileName, NAME_OF_FILE_WITH_USERS);
    }
}