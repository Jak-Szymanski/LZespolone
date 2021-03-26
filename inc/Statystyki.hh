#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

struct Statystyka{
    int poprawne;
    double wszystkie;

    void Wyzeruj();
    void Poprawnie();
    void Niepoprawnie();
};

#endif