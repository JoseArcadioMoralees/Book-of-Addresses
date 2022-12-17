#include"UsersManager.h"

void UsersManager::registerAnUser()
{
    User user = giveDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToTheFile(user);

    cout << endl
         << "Konto zalozono pomyslnie" << endl
         << endl;
    system("pause");
}

User UsersManager::giveDataOfNewUser()
{
    User user;
    user.setId(getIdOfNewUser());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin.sync(); 
        cin >> login;
        user.setLogin(login);
    } while (ifLoginExist(user.getLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    user.setPassword(haslo);

    return user;
}

int UsersManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UsersManager::ifLoginExist(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl
                 << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UsersManager::showAllUsers()
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl; 
        cout << users[i].getLogin() << endl; 
        cout << users[i].getPassword() << endl; 
    }
}


void UsersManager::loggingAnUser()
{
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadALine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadALine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idOFLoggedUser = itr -> getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
void UsersManager::changePasswordOfLoggedUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadALine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idOFLoggedUser)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    saveAllUSersToFile();
}

void UsersManager::saveAllUSersToFile()
{
    fstream textFile;
    string lineWithDataOfUser = "";
    vector <User>::iterator itrEnd = --users.end();
    string nameOfFileWithUsers = fileWithUsers.getNameOfFileWithUsers();

    textFile.open(nameOfFileWithUsers.c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithDataOfUser = fileWithUsers.replaceUserDataIntoLineWithDataSeparatedWithVerticalBars(*itr);

            if (itr == itrEnd)
            {
               textFile << lineWithDataOfUser;
            }
            else
            {
                textFile << lineWithDataOfUser << endl;
            }
            lineWithDataOfUser = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nameOfFileWithUsers << endl;
    }
    textFile.close();
}

int UsersManager::getIdOfLoggedUser()
{
    return idOFLoggedUser; 
}

void UsersManager::setIdOfLoggedUser(int IDOFLOGGEDUSER)
{
    idOFLoggedUser = IDOFLOGGEDUSER; 
}
