#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include "Statystyki.hh"

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*przeciążenia operatorów dla operacji matematycznych na liczbach zespolonych*/
LZespolona Sprzezenie(LZespolona Skl1);
double Modul2(LZespolona Skl1);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, double Liczba);

bool operator == (LZespolona Skl1, LZespolona Skl2);

istream& operator >> (istream &wejscie, LZespolona &LZesp);
ostream& operator << (ostream &wyjscie, LZespolona &LZesp);

#endif
