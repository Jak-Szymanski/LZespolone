# Projekt 2 - Arytmetyka liczb zespolonych

## Cel ćwiczenia
Wykształcenie umiejętności definiowania przeciążeń operatorów arytmetycznych dwuargumentowych i jednoargumentowych dla własnych struktur danych oraz operatora porównania. Przećwiczenie podstawowych operacji na strumieniach plikowych.  Nabycie umiejętności definiowania przeciążeń operacji na strumieniach.

## Opis zadania programowego
Należy napisać program, który umożliwia wykonanie prostego sprawdzianu z arytmetyki liczb zespolonych.  Sprawdzian ma dotyczyć operacji dodawania, odejmowania, mnożenia i dzielenia. Zakłada się, ̇ze są dostępne co najmniej dwa zestawy pytań. Dla uproszczenia zakładamy, ̇ze liczby zespolone będą wyświetlane w nawiasach. W tej formie będą również wprowadzane. Przykładowy zapis wyrażeń podany jest poniżej.

	(4.2+2i)+(0+2i)
	(3-0i)*(-1+2.1i)
	(0-4i)/(3-1i)

W zapisie tym dla ułatwienia zachowanych jest kilka reguł:
* każda liczba zespolona zawsze zapisywana jest w nawiasach półokrągłych,
* zawsze występuje liczba oznaczająca część rzeczywistą, niezależnie od tego czy jest ona różna od zera, czy też równa jest zeru,
* zawsze  występuje  liczba  oznaczająca  część urojoną, niezależnie od tego czy jest ona różna od zera, czy też równa jest zeru,
* zestaw pytań zakończony jest znakiem kropki.

W trakcie realizacji testu program wyświetla kolejne wyrażenie i pyta użytkownika o wyniko peracji.  Udzieloną odpowiedź sprawdza z poprawnym wynikiem.  W przypadku poprawnej odpowiedzi, potwierdza ten fakt, zaś w przypadku błędnej odpowiedzi stwierdza ten fakt i podaje odpowiedź właściwą.  Po zakończeniu testu podawana jest statystyka błędnych i poprawnych odpowiedzi.


## Struktura repozytorium
Repozytorium z zalążkiem do zadania ma następującą strukturę:

&nbsp;&nbsp; [src](src/) - folder z plikami źródłowymi\
&nbsp;&nbsp; [inc](inc/)-- folder z plikami nagłówkowymi\
&nbsp;&nbsp; [tests](tests/) - zawiera pliki źródłowe testów oraz biblioteki doctest\
&nbsp;&nbsp; ├── bin - pliki binarne testów\
&nbsp;&nbsp; └── doctest - pliki źródłowe dla biblioteki odpowiedzialnej za testy\
&nbsp;&nbsp; [man](man/) - instrukcje do zadania oraz inne pomoce naukowe\
&nbsp;&nbsp; Makefile - plik z dyrektywami do automatycznej kompilacji\
&nbsp;&nbsp; .gitignore  - plik określający, które pliki mają być ignorowane przez Gita\

## Odnośniki do źródeł
[Strona kursu z Programowania Obiektowego](https://kcir.pwr.edu.pl/~kreczmer/po/)



