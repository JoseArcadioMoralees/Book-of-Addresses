#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
using namespace std;

class FileWithUsers
{
    const string NAME_OF_FILE_WITH_USERS; 
    User getDataofUser(string dataOfUserSeparatedByVerticalLines);

public: 
    FileWithUsers(string nameOfFileWithUsers) : NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers){}; 
    
    void addUserToTheFile(User user);
    vector <User> loadUsersFromFile(); 
    string getNameOfFileWithUsers(); 
    static string replaceUserDataIntoLineWithDataSeparatedWithVerticalBars(User user);
    
};

#endif