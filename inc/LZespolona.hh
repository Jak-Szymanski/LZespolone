#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include "Statystyki.hh"

using namespace std;

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  /*przeciążenia operatorów dla operacji matematycznych na liczbach zespolonych*/
  void Sprzezenie();
  double Modul2();
  LZespolona  operator + (LZespolona  Skl2);
  LZespolona operator - (LZespolona Skl2);
  LZespolona operator * (LZespolona Skl2);
  LZespolona operator / (LZespolona Skl2);
  LZespolona operator / (double Liczba) const;
  bool operator == (LZespolona Skl2) const;

  /* przeciążenia operatorów dla operacji na strumieniach na liczbach zespolonych */
  friend istream& operator >> (istream &wejscie, LZespolona &LZesp);
  friend ostream& operator << (ostream &wyjscie, LZespolona &LZesp);
};

#endif
