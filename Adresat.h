#ifndef ADRESAT_H
#define ADRESAT_H
#include<iostream>

using namespace std; 

class Adresat
{
    int id = 0, idUzytkownika = 0;
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";

public:
    int getId();
    int getIdUzytkownika();
    string getImie(); 
    string getNazwisko(); 
    string getNumerTelefonu(); 
    string getEmail(); 
    string getAdres(); 

    void setId(int);
    void setIdUzytkownika(int);
    void setImie(string); 
    void setNazwisko(string); 
    void setNumerTelefonu(string); 
    void setEmail(string); 
    void setAdres(string);
};

#endif