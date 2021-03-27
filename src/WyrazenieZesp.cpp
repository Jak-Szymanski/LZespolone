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


istream& operator >> (istream &wejscie, WyrazenieZesp &WyrZ) {
    wejscie >> WyrZ.Arg1;
    if(wejscie.fail()){
        wejscie.setstate(ios::failbit);
        return wejscie;
    }
    wejscie >> WyrZ.Op;
    if(wejscie.fail()){
        wejscie.setstate(ios::failbit);
        return wejscie;
    }
    wejscie >> WyrZ.Arg2;
    if(wejscie.fail()){
        wejscie.setstate(ios::failbit);
        return wejscie;
    }
    wejscie.setstate(ios::goodbit);
    return wejscie;
}


istream& operator >> (istream &wejscie, Operator &Op) {
    char Oper;
    wejscie >> Oper;
    switch(Oper){
        case '+':
            Op = Op_Dodaj;
        break;
        case '-':
            Op = Op_Odejmij;
        break;
        case '*':
            Op = Op_Mnoz;
        break;
        case '/':
            Op = Op_Dziel;
        break; 
        default:
        wejscie.setstate(ios::failbit);
        break;  
    }
    return wejscie; 
}

/* Oblicza podane wyrażenie zespolone
Argumenty:
    WyrZ - wyrażenie zespolone
Zwraca:
    Wynik operacji jako liczba zespolona
 */
LZespolona WyrazenieZesp::Oblicz(){
    
    LZespolona Wynik;
    switch(this->Op){
        case Op_Dodaj:
            Wynik = this->Arg1 + this->Arg2;
        break;
        case Op_Odejmij:
            Wynik = this->Arg1 - this->Arg2;
        break;
        case Op_Mnoz:
            Wynik = this->Arg1 * this->Arg2;
        break;
        case Op_Dziel:
            Wynik = this->Arg1 / this->Arg2;
        break;       
    }
    return Wynik;
}