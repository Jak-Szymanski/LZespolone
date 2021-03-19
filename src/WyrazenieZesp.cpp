#include <iostream>
#include "WyrazenieZesp.hh"
using namespace std;


/* Wyświetla wyrażenie operacji na liczbach zespolonych
Argumenty:
    wyjscie - adres wyjścia standardowego
    WyrZ - wyrażenie zespolone
Zwraca:
    adres wyjścia standardowego
 */
ostream& operator << (ostream &wyjscie, WyrazenieZesp &WyrZ){
    wyjscie << WyrZ.Arg1;
    switch(WyrZ.Op){
        case Op_Dodaj:
        wyjscie << " + ";
        break;
        case Op_Odejmij:
        wyjscie << " - ";
        break;
        case Op_Mnoz:
        wyjscie << " * ";
        break;
        case Op_Dziel:
        wyjscie << " / ";
        break;
    }
    wyjscie << WyrZ.Arg2;
    return wyjscie;
}

/* Oblicza podane wyrażenie zespolone
Argumenty:
    WyrZ - wyrażenie zespolone
Zwraca:
    Wynik operacji jako liczba zespolona
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    
    LZespolona Wynik;
    switch(WyrZ.Op){
        case Op_Dodaj:
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;
        case Op_Odejmij:
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;
        case Op_Mnoz:
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;
        case Op_Dziel:
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;       
    }
    return Wynik;
}