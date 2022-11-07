#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

    public: 
    void ustawID(int noweID);
    void ustawLogin(string nowyLogin);
    void ustawHAslo(string noweHaslo); 

    int pobierzID();
    string pobierzLogin(); 
    string pobierzHaslo(); 
}; 