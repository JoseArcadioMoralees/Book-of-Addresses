#include "Adresat.h"

int Adresat::getId()
{
    return id; 
}
int Adresat::getIdUzytkownika()
{
    return idUzytkownika; 
}
string Adresat::getImie()
{
    return imie; 
}
string Adresat::getNazwisko()
{
    return nazwisko; 
} 
string Adresat::getNumerTelefonu()
{
    return numerTelefonu; 
} 
string Adresat::getEmail()
{
    return email; 
} 
string Adresat::getAdres()
{
    return adres; 
}

void Adresat::setId(int ID)
{
    id = ID; 
}
void Adresat::setIdUzytkownika(int IDUZYTKOWNIKA)
{
    idUzytkownika = IDUZYTKOWNIKA; 
}
void Adresat::setImie(string IMIE)
{
    imie = IMIE; 
}
void Adresat::setNazwisko(string NAZWISKO)
{
    nazwisko = NAZWISKO; 
}
void Adresat::setNumerTelefonu(string NUMERTELEFONU)
{
    numerTelefonu = NUMERTELEFONU; 
}
void Adresat::setEmail(string EMAIL)
{
    email = EMAIL; 
}
void Adresat::setAdres(string ADRES)
{
    adres = ADRES; 
}