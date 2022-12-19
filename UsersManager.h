#ifndef USERSMANAGER_H
#define USERSMANAGER_H
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UsersManager
{
    int idOFLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers; 
    User giveDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginExist(string login);

public:
    UsersManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) 
    {
        idOFLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerAnUser();
    void showAllUsers(); 
    void loggingAnUser();
    void changePasswordOfLoggedUser();
    void saveAllUSersToFile(); 
    int getIdOfLoggedUser();
    void setIdOfLoggedUser(int);
};

#endif