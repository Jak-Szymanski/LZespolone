#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona równe"){
    LZespolona x, y;

    x.re = 5;
    x.im = -5;

    y.re = 5;
    y.im = -5;

    CHECK(x == y);
}

TEST_CASE("test LZespolona nierówne"){
    LZespolona x, y;

    x.re = 5;
    x.im = -5;

    y.re = 0.02;
    y.im = 4;

    CHECK(!(x == y));
}

TEST_CASE("test LZespolona minimalnie nierówne"){
    LZespolona x, y;

    x.re = 0;
    x.im = 0;

    y.re = 0.01;
    y.im = -0.0111;

    CHECK(!(x == y));
}

TEST_CASE("test LZespolona nierówne rząd mniej od MIN_DIFF"){
    LZespolona x, y;

    x.re = 0;
    x.im = 0;

    y.re = 0.00009;
    y.im = -0.00001;

    CHECK(x == y);
}

TEST_CASE("test LZespolona dodawanie 0+0i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0;
    y.im = 0;

    CHECK(x+y == x);
}

TEST_CASE("test LZespolona dodawanie 0.0+0.0i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0.0;
    y.im = 0.0;

    CHECK(x+y == x);
}

TEST_CASE("test LZespolona dodawanie 0.00001+0.00001i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0.00001;
    y.im = 0.00001;

    CHECK(x+y == x);
}

TEST_CASE("test LZespolona dodawanie na granicach"){
    LZespolona x, y;

    x.re = 0.00009;
    x.im = 0.00009;

    y.re = 0.00001;
    y.im = 0.00001;

    CHECK(x+y == x);
}

TEST_CASE("test LZespolona odejmowanie 0+0i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0;
    y.im = 0;

    CHECK(x-y == x);
}

TEST_CASE("test LZespolona odejmowanie 0.0+0.0i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0.0;
    y.im = 0.0;

    CHECK(x-y == x);
}

TEST_CASE("test LZespolona odejmowanie 0.00001+0.00001i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0.00001;
    y.im = 0.00001;

    CHECK(x-y == x);
}

TEST_CASE("test LZespolona odejmowanie na granicach"){
    LZespolona x, y;

    x.re = 0.50001;
    x.im = 0.50001;

    y.re = 0.00001;
    y.im = 0.00001;

    CHECK(x-y == x);
}

TEST_CASE("test LZespolona mnożenie 0+0i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 0;
    y.im = 0;

    CHECK(x*y == y);
}

TEST_CASE("test LZespolona mnożenie 1+0i"){
    LZespolona x, y;

    x.re = 3;
    x.im = 3;

    y.re = 1;
    y.im = 0;

    CHECK(x*y == x);
}

TEST_CASE("test LZespolona mnożenie 0+1i"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 3;

    y.re = 0;
    y.im = 1;

    z.re = -3;
    z.im = 3;

    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnożenie 1+1i"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 3;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 6;

    CHECK(x*y == z);
}

TEST_CASE("test LZespolona mnożenie wartości minimalne"){
    LZespolona x, y;

    x.re = 1;
    x.im = 1;

    y.re = 1.00001;
    y.im = 0.00001;

    CHECK(x*y == x);
}

TEST_CASE("Test LZespolona dzielenie przez skalar") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t); 
}

TEST_CASE("Test LZespolona dzielenie przez zespolona") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 0;
   
    CHECK(x/y == x);
}

TEST_CASE("Test LZespolona dzielenie przez zespolona - zero") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;
   
    WARN_THROWS(x/y);
}

TEST_CASE("Test LZespolona sprzezenie") {
    LZespolona x, y;

    x.re = 4;
    x.im = 5;
    x.Sprzezenie();

    y.re = 4;
    y.im = -5;

    CHECK(x == y);
}

TEST_CASE("Test LZespolona sprzezenie - zero") {
    LZespolona x, y;

    x.re = 4;
    x.im = 0;
    x.Sprzezenie();

    y.re=4;
    y.im=0;

    CHECK(x == y);
}

TEST_CASE("Test LZespolona modul") {
    LZespolona x;
    double t;

    x.re = 3;
    x.im = 4;

    t = 25;
    
    CHECK( x.Modul2() == t);
}

TEST_CASE("Test LZespolona wyświetlanie zaokrąglane") {
    LZespolona x;

    x.re = 2.0/3.0;
    x.im = 2.0/3.0;

    ostringstream out;
    out << x;

    CHECK("(0.66+0.66i)" == out.str());
}