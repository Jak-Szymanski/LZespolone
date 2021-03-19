#include <iostream>
#include <cmath>
#include <iomanip>
#include "LZespolona.hh"

#define MIN_DIFF 0.0001

using namespace std;

/* Wykonuje sprzężenie liczby zespolonej
Argumenty:
  Skl1 - liczba zespolona
Zwraca:
  Sprzężenie liczby Skl1
 */
LZespolona Sprzezenie(LZespolona Skl1){
  Skl1.im = -Skl1.im;
  return Skl1;
}

/* Oblicza kwadrat modułu liczby zespolonej
Argumenty:
  Skl1 - liczba zespolona
Zwraca:
  Kwadrat modułu liczby Skl1
 */
double Modul2(LZespolona Skl1){
  return Skl1.re*Skl1.re + Skl1.im * Skl1.im;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania
 *    Skl2 - drugi skladnik dodawania
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna
 *    Skl2 - odjemnik
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2){

  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia
 *    Skl2 - drugi skladnik mnożenia
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2){

  LZespolona Wynik;

  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.im*Skl2.re + Skl1.re*Skl2.im;
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
LZespolona operator / (LZespolona Skl1, LZespolona Skl2){

  LZespolona Wynik;
  Wynik = (Skl1 * Sprzezenie(Skl2)) / Modul2(Skl2);
  return Wynik;
}

/* Realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą.
Argumenty:
  Skl1 - dzielna (liczba zespolona)
  Liczba - dzielnik (liczba rzeczywista)
Zwraca:
  Iloraz dwóch skladników przekazanych jako parametry (liczb. zesp.)
 */
LZespolona operator / (LZespolona Skl1, double Liczba){
  
  if(Liczba == 0){
    throw invalid_argument("Błąd - dzielenie przez zero");
  }
  LZespolona Wynik;
  Wynik.re = Skl1.re / Liczba;
  Wynik.im = Skl1.im / Liczba;
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
bool operator == (LZespolona Skl1, LZespolona Skl2){

  if((abs(Skl1.re - Skl2.re) < MIN_DIFF) && (abs(Skl1.im - Skl2.im) < MIN_DIFF)){
    return 1;
  } else {
    return 0;
  }
}


/* Wczytuje liczbe zespoloną z wejścia standardowego
Argumenty:
  wejscie - adres wejscia standardowego
  LZesp - adres zmiennej do której będzie wpisana liczba zespolona
Zwraca:
  adres wejścia standardowego
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

/* Wyświetla pojedynczą liczbę zespoloną
Argumenty:
    wyjscie - adres wyjścia standardowego
    LZesp - Liczba Zespolona do wyświetlenia
Zwraca:
    adres wyjścia standardowego
*/
ostream& operator << (ostream &wyjscie, LZespolona &LZesp){
    wyjscie << "("<< fixed << setprecision (4) << LZesp.re << showpos << fixed << setprecision (4) << LZesp.im  << noshowpos << "i)";
    return wyjscie;
}

