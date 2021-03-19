#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>
#include <sstream>
#include <string>

/* using namespace std;

string toString( ostream& str){
    ostringstream ss;
    ss << str.rdbuf();
    return ss.str();
}


TEST_CASE("Test wyswietlania wyrazenia"){

    WyrazenieZesp x;

    x.Arg1.re = 1;
    x.Arg1.im = -2;

    x.Op = Op_Dodaj;

    x.Arg2.re = -3;
    x.Arg2.im = 4;

    stringstream stream;
    stream << x;
    string g = toString(stream);
    string str;
    str = "(1-2i) + (-3+4i)";
    CHECK(str == g); 
    }*/

/* TEST_CASE("Test WyrazenieZesp dodawanie") {
    WyrazenieZesp x;
    LZespolona y, z;

    x.Arg1.re = 1;
    x.Arg1.im = -2;

    x.Op = Op_Dodaj;
   
    x.Arg2.re = -3;
    x.Arg2.im = 4;

    y.re = -2;
    y.im = 2;

    z = Oblicz(x);
    CHECK(y == z);
} */

/* TEST_CASE("Test WyrazenieZesp odejmowanie") {
    WyrazenieZesp x;
    LZespolona y, z;

    x.Arg1.re = 1;
    x.Arg1.im = -2;

    x.Op = Op_Odejmij;
   
    x.Arg2.re = -3;
    x.Arg2.im = 4;

    y.re = 2;
    y.im = -6;

    z = Oblicz(x);
    CHECK(y == z);
} */



