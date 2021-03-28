#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{
 
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  if(strcmp(argv[1], "latwy") && strcmp(argv[1], "trudny")){
    cout << endl;
    cout << "Niepoprawne okreslenie rodzaju testu" << endl;
    cout << "Dopuszczalne nazwy to:  latwy, trudny." << endl;
    return 1;
  }

  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  int i;                   
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona      Odpowiedz;    
  LZespolona      Wynik;
  Statystyka      StatOdp;
  StatOdp.Wyzeruj();
  ifstream file ((string)argv[1] + ".txt");

  if (file.is_open()) {
    while (!file.eof()) {
      if (file.eof()) {
        break;
      }else {
      file >> WyrZ_PytanieTestowe;
      if(file.fail()){
        file.clear();
        file.ignore(256, '\n');
        cout << "Blad we wczytywaniu wyrazenia z pliku" << endl << endl;
        continue;
      }
      
      cout << "Podaj wynik operacji: " << WyrZ_PytanieTestowe << " = " << endl;
      cout << endl << "Twoja odpowiedz:  " << endl;
      cin >> Odpowiedz;
      if(cin.fail()){
        for(i=0;i<2;i++){
          cin.clear();
          cin.ignore(256, '\n');
          cout << endl;
          cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
          cout << endl << "Twoja odpowiedz:  " << endl;
          cin >> Odpowiedz;
          if(!cin.fail()){
            break;
          }    
        }
        if(cin.fail()){
          cout << "Przekroczono liczbę błędów zapisu liczby zespolonej." << endl;
        }
        cin.clear();
        cin.ignore(256, '\n');
      }
      cout << endl;
      try{
        Wynik = WyrZ_PytanieTestowe.Oblicz();
        if(Odpowiedz == Wynik){
          cout << " :) Odpowiedz poprawna! " << endl << endl;
          StatOdp.Poprawnie();
        } else {
          cout << " :( Odpowiedz niepoprawna, prawidlowy wynik: " << Wynik << endl << endl; 
          StatOdp.Niepoprawnie();
        }
      }
      catch (runtime_error& e) {
        cerr << "Wystąpił błąd" << endl << e.what() << endl; 
      }
      }
    }
    file.close();
    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    if(StatOdp.wszystkie !=0){
    cout << "Ilosc dobrych odpowiedzi: " << StatOdp.poprawne << endl;
    cout << "Ilosc blednych odpowiedzi: " << StatOdp.wszystkie - StatOdp.poprawne << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << 100 * StatOdp.poprawne / StatOdp.wszystkie << "%" << endl;
    }
    return 0;

  } else {
    cerr << "Błąd w otwieraniu pliku" << endl;
    return 1;
  }
}