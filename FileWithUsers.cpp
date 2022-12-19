#include "FileWithUsers.h"

void FileWithUsers::addUserToTheFile(User user)
{
    fstream textFile;
    string lineWithDataOfUser = "";
    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithDataOfUser = replaceUserDataIntoLineWithDataSeparatedWithVerticalBars(user);

        if (AuxiliaryMethods::ifFileIsEmpty(textFile) == true)
        {
            textFile << lineWithDataOfUser;
        }
        else
        {
            textFile << endl << lineWithDataOfUser ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << NAME_OF_FILE_WITH_USERS << " i zapisac w nim danych." << endl;
    textFile.close();
}


string FileWithUsers::replaceUserDataIntoLineWithDataSeparatedWithVerticalBars(User user)
{
    string lineWithDataOfUser = "";

    lineWithDataOfUser += AuxiliaryMethods::convertIntToString(user.getId())+ '|';
    lineWithDataOfUser += user.getLogin() + '|';
    lineWithDataOfUser += user.getPassword() + '|';

    return lineWithDataOfUser;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    fstream textFile;
    User user;
    vector <User> users;
    string dataOfUserSeparatedByVerticalBars = "";

    textFile.open(NAME_OF_FILE_WITH_USERS.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, dataOfUserSeparatedByVerticalBars))
        {
            user = getDataofUser(dataOfUserSeparatedByVerticalBars);
            users.push_back(user);
        }
        textFile.close();
    }
    return users; 
}

User FileWithUsers::getDataofUser(string dataOfUserSeparatedByVerticalLines)
{
    User user;
    string singleDataOfUser = "";
    int numberOfSingleDataOfUser = 1;

    for (unsigned int positionOfCharacter = 0; positionOfCharacter < dataOfUserSeparatedByVerticalLines.length(); positionOfCharacter++)
    {
        if (dataOfUserSeparatedByVerticalLines[positionOfCharacter] != '|')
        {
            singleDataOfUser += dataOfUserSeparatedByVerticalLines[positionOfCharacter];
        }
        else
        {
            switch(numberOfSingleDataOfUser)
            {
            case 1:
                user.setId(atoi(singleDataOfUser.c_str()));
                break;
            case 2:
                user.setLogin(singleDataOfUser);
                break;
            case 3:
                user.setPassword(singleDataOfUser);
                break;
            }
            singleDataOfUser = "";
            numberOfSingleDataOfUser++;
        }
    }
    return user;
}

string FileWithUsers::getNameOfFileWithUsers()
{
    return NAME_OF_FILE_WITH_USERS; 
}
