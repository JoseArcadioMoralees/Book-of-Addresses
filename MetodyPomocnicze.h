#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include<iostream>
#include<sstream>

using namespace std;

class MetodyPomocnicze
{
public: 
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie(); 
    static char wybierzOpcjeZMenuGlownego(); 
    static char wczytajZnak();
    static char wybierzOpcjeZMenuUzytkownika(); 
    static int konwersjaStringNaInt(string liczba); 
    static string pobierzLiczbe(string tekst, int pozycjaZnaku); 
    static int wczytajLiczbeCalkowita(); 
    static char wybierzOpcjeZMenuEdycja();
    static void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow); 
};



#endif