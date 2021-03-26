#include "Statystyki.hh"

void Statystyka::Wyzeruj(){
    this->poprawne = 0;
    this->wszystkie = 0.0;
}


 void Statystyka::Poprawnie(){
    this->poprawne+=1;
    this->wszystkie+=1.0;
}


void Statystyka::Niepoprawnie(){
    this->wszystkie+=1.0;
}