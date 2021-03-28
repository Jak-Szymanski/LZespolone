#include <iostream>
#include <cmath>
#include <iomanip>
#include "LZespolona.hh"

#define MIN_DIFF 0.01

using namespace std;

/* Wykonuje sprzężenie liczby zespolonej
Argumenty:
  Skl1 - liczba zespolona
Zwraca:
  Sprzężenie liczby Skl1
 */
void LZespolona::Sprzezenie(){
  this->im = -this->im;
}

/* Oblicza kwadrat modułu liczby zespolonej
Argumenty:
  Skl1 - liczba zespolona
Zwraca:
  Kwadrat modułu liczby Skl1
 */
double LZespolona::Modul2(){
  return this->re*this->re + this->im * this->im;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania
 *    Skl2 - drugi skladnik dodawania
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2){

  Skl2.re += this -> re;
  Skl2.im += this -> im;
  return Skl2;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna
 *    Skl2 - odjemnik
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (LZespolona Skl2){

  Skl2.re = this->re - Skl2.re;
  Skl2.im = this->im - Skl2.im;
  return Skl2;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia
 *    Skl2 - drugi skladnik mnożenia
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator * (LZespolona Skl2){

  LZespolona Wynik;
  Wynik.re = this->re*Skl2.re - this->im*Skl2.im;
  Wynik.im = this->im*Skl2.re + this->re*Skl2.im;
  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - dzielna
 *    Skl2 - dzielnik
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (LZespolona Skl2){

  LZespolona Wynik;
  Skl2.Sprzezenie();
  Wynik = (*this * Skl2) / Skl2.Modul2();
  return Wynik;
}

/* Realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą.
Argumenty:
  Skl1 - dzielna (liczba zespolona)
  Liczba - dzielnik (liczba rzeczywista)
Zwraca:
  Iloraz dwóch skladników przekazanych jako parametry (liczb. zesp.)
 */
LZespolona LZespolona::operator / (double Liczba) const{
  
  if(Liczba == 0){
    throw runtime_error("Dzielenie przez zero \n");
  }
  LZespolona Wynik;
  Wynik.re = this->re / Liczba;
  Wynik.im = this->im / Liczba;
  return Wynik;
}

/* Porownuje dwie liczby zespolone z pewną tolerancją
Argumenty:
  Skl1 - pierwsza liczba zespolona
  Skl2 - druga liczba zespolona
Zwraca:
  1 - gdy te liczby są sobie prawie równe
  0 - gdy te liczby nie są sobie wcale równe
 */
bool LZespolona::operator == (LZespolona Skl2) const{

  if((abs(this->re - Skl2.re) <= MIN_DIFF) && (abs(this->im - Skl2.im) <= MIN_DIFF)){
    return 1;
  } else {
    return 0;
  }
}


/* Wczytuje liczbę zespoloną ze strumienia
Argumenty:
  wejscie - adres strumienia
  LZesp - adres zmiennej do której będzie wpisana liczba zespolona
Zwraca:
  adres strumienia
 */
istream& operator >> (istream &wejscie, LZespolona &LZesp){

    char Nawias, Litera;
    wejscie >> Nawias;
    if (wejscie.fail())
        return wejscie;
    if (Nawias != '('){
        wejscie.setstate(ios::failbit);
        return wejscie;
    }
    wejscie >> LZesp.re;
    if (wejscie.fail())
        return wejscie;
    wejscie >> LZesp.im;
    if (wejscie.fail())
        return wejscie;
    wejscie >> Litera;
    if (wejscie.fail())
        return wejscie;
    if (Litera != 'i'){
        wejscie.setstate(ios::failbit);
        return wejscie;
    }
    wejscie >> Nawias;
    if (wejscie.fail())
        return wejscie;
    if (Nawias != ')'){
        wejscie.setstate(ios::failbit);
        return wejscie;
    }

    wejscie.setstate(ios::goodbit);
    return wejscie;
}

/* Wpisuje liczbę zespoloną do strumienia
Argumenty:
    wyjscie - adres strumienia
    LZesp - adres liczby zespolonej do wyświetlenia
Zwraca:
    adres strumienia
*/
ostream& operator << (ostream &wyjscie, LZespolona &LZesp){
    double re = (int)(LZesp.re * 100);
    double im = (int)(LZesp.im * 100);
    wyjscie << "(" << (double)re/100 << showpos << (double)im/100  << noshowpos << "i)";
    return wyjscie;
}

