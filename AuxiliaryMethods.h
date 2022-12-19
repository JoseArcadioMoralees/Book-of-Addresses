#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

class AuxiliaryMethods
{
public: 
    static string convertIntToString(int number);
    static string loadALine(); 
    static char choseOptionFromMainMenu(); 
    static char loadCharacter();
    static char choseOptionFromUserMenu(); 
    static int convertStringToInt(string number); 
    static string loadNumber(string text, int positionOfCharacter); 
    static int loadIntegerNumber(); 
    static char choseOptionFromEditionMenu();
    static void displayNumberOfSearchedRecipients(int numberOfRecipients); 
    static bool ifFileIsEmpty(fstream &textFile); 
};



#endif