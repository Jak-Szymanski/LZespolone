#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("Test WyrazenieZesp dodawanie") {
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



