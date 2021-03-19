#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

struct Statystyka{
    int poprawne;
    double wszystkie;
};


Statystyka Wyzeruj(Statystyka Stat);
Statystyka Poprawnie(Statystyka Stat);
Statystyka Niepoprawnie(Statystyka Stat);
#endif