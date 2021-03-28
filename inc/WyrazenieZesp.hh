#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

using namespace std;


#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

istream& operator >> (istream &wejscie, Operator &Op);


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  /*przeciążenia operatorów dla wyrażeń zespolonych*/
  friend ostream& operator << (ostream &wyjscie, WyrazenieZesp &WyrZ);
  friend istream& operator >> (istream &wejscie, WyrazenieZesp &WyrZ);
  LZespolona Oblicz();
};





#endif
