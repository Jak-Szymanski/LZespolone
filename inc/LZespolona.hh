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

  void Sprzezenie();
  double Modul2();
  LZespolona  operator + (LZespolona  Skl2);
  LZespolona operator - (LZespolona Skl2);
  LZespolona operator * (LZespolona Skl2);
  LZespolona operator / (LZespolona Skl2);
  LZespolona operator / (double Liczba) const;
  bool operator == (LZespolona Skl2) const;
  friend istream& operator >> (istream &wejscie, LZespolona &LZesp);
  friend ostream& operator << (ostream &wyjscie, LZespolona &LZesp);
};


/*przeciążenia operatorów dla operacji matematycznych na liczbach zespolonych*/

#endif
