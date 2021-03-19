#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
#include "LZespolona.hh"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

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
    str = "(1.0000-2.0000i) + (-3.0000+4.0000i)";
    CHECK(str == g); 
}

TEST_CASE("Test WyrazenieZesp oblicz") {
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
}

TEST_CASE("test Statystyki poprawna odp"){
    Statystyka x;

    x.poprawne = 3;
    x.wszystkie = 5;

    x = Poprawnie(x);

    CHECK(x.poprawne == 4);
    CHECK(x.wszystkie == 6);
}

TEST_CASE("test Statystyki niepoprawna odp"){
    Statystyka x;

    x.poprawne = 3;
    x.wszystkie = 5;

    x = Niepoprawnie(x);

    CHECK(x.poprawne == 3);
    CHECK(x.wszystkie == 6);
}




