#include "Statystyki.hh"

Statystyka Wyzeruj(Statystyka Stat){
    Stat.poprawne = 0;
    Stat.wszystkie = 0.0;
    return Stat;
}


Statystyka Poprawnie(Statystyka Stat){
    Stat.poprawne+=1;
    Stat.wszystkie+=1.0;
    return Stat;
}


Statystyka Niepoprawnie(Statystyka Stat){
    Stat.wszystkie+=1.0;
    return Stat;
}