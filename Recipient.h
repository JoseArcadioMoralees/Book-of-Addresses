#ifndef RECIPIENT_H
#define RECIPIENT_H
#include<iostream>

using namespace std; 

class Recipient
{
    int id = 0, usersId = 0;
    string name = "", surname = "", phoneNumber = "", email = "", address = "";

public:
    int getId();
    int getIdOfUser();
    string getName(); 
    string getSurname(); 
    string getPhoneNumber(); 
    string getEmail(); 
    string getAddress(); 

    void setId(int);
    void setIdOfUser(int);
    void setName(string); 
    void setSurname(string); 
    void setPhoneNumber(string); 
    void setEmail(string); 
    void setAddress(string);
};

#endif