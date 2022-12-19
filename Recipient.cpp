#include "Recipient.h"

int Recipient::getId()
{
    return id; 
}
int Recipient::getIdOfUser()
{
    return usersId; 
}
string Recipient::getName()
{
    return name; 
}
string Recipient::getSurname()
{
    return surname; 
} 
string Recipient::getPhoneNumber()
{
    return phoneNumber; 
} 
string Recipient::getEmail()
{
    return email; 
} 
string Recipient::getAddress()
{
    return address; 
}

void Recipient::setId(int ID)
{
    id = ID; 
}
void Recipient::setIdOfUser(int USERSID)
{
    usersId = USERSID; 
}
void Recipient::setName(string NAME)
{
    name = NAME; 
}
void Recipient::setSurname(string SURNAME)
{
    surname = SURNAME; 
}
void Recipient::setPhoneNumber(string PHONENUMBER)
{
    phoneNumber = PHONENUMBER; 
}
void Recipient::setEmail(string EMAIL)
{
    email = EMAIL; 
}
void Recipient::setAddress(string ADDRESS)
{
    address = ADDRESS; 
}