#include "rectagle.hh"

#define MAX_DIFF 0.0000000001



/*!
 * Przeciazenie operatora bitowego dla wyswietladnia Rectanglea
 * Argumenty:
 *  &Strm - referencja do strumienia wyjsciowego
 *  &Pr - Rectangle, ktory zostanie wyswietlony
 * Zwraca:
 *  Strumien wyjsciowy z Rectangleem
 */

std::ostream& operator << (std::ostream &Strm, const Rectangle &Pr) {
    for(int i=0; i< REC; i++) {
        Strm << Pr.Corners[i] << std::endl;
    }
    return Strm;
}



/*!
 * Przeciazenie operatora bitowego dla wczytywania Rectanglea
 * Argumenty:
 *  &Strm - referencja do strumienia wejsciowego
 *  &Pr -  referencja do wprowadzanego Rectanglea
 * Zwraca:
 *  Strumien wejsciowy z Rectangleem
 */

std::istream& operator >> (std::istream &Strm, Rectangle &Pr) {
    for(int i=0; i< REC; i++) {
        Strm >> Pr.Corners[i];
    }
    return Strm;
}



/*!
 * Realizuje translacje Rectanglea o zadany wektor
 * Argumenty:
 *  wektor - wektor, o jaki ma zostac wykonana translacja
 * Zwraca:
 *  Rectangle po przesunieciu o zadany wektor
 */

Rectangle Rectangle::translacja(Vector wektor) {
    for(int i=0; i<REC; i++) {
        this->Corners[i] = this->Corners[i] + wektor;
    }
    return *this;
}




/*!
 * Realizuje obrot Rectanglea wokol poczatku ukladu wspolrzednych
 * o zadany kat podana ilosc razy
 * Argumenty:
 *  kat - kat o jaki zostanie wykonany obrot
 *  ilosc - ilosc obrotow
 * Zwraca:
 *  Rectangle po wykonaniu obrotu
 */

Rectangle Rectangle::obrot(double kat, int ilosc) {
    Matrix obrot;
    obrot.MacierzObrotu(kat);
    for(int j=0; j<ilosc; j++){
        for(int i=0; i<REC; i++) {
            this->Corners[i] = obrot * this->Corners[i];
        }
    }
    return *this;
}


/*!
 * Wyswietla dlugosci bokow Rectanglea oraz sprawdza, czy przeciwne boki sa tej samej dlugosci
 * Argumenty:
 * Zwraca:
 */

void Rectangle::boki() {
    double a, b, c, d; // dlugosci bokow
    a = sqrt(pow(this->Corners[0][0] - this->Corners[1][0],2)+pow(this->Corners[0][1]-this->Corners[1][1],2));
    b = sqrt(pow(this->Corners[2][0] - this->Corners[3][0],2)+pow(this->Corners[2][1]-this->Corners[3][1],2));
    c = sqrt(pow(this->Corners[0][0] - this->Corners[3][0],2)+pow(this->Corners[0][1]-this->Corners[3][1],2));
    d = sqrt(pow(this->Corners[1][0] - this->Corners[2][0],2)+pow(this->Corners[1][1]-this->Corners[2][1],2));
    
    if(a >= b-MAX_DIFF && a<=b+MAX_DIFF) {
        if(a > c) {
            std::cout << ":)\tDluzsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
        else {
            std::cout << ":)\tKrotsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
    }
    else {
        if(a > c) {
            std::cout << ":O\tDluzsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
        else {
            std::cout << ":O\tKrotsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
    }
    if(c >= d-MAX_DIFF && c<=d+MAX_DIFF) {
        if(a < c) {
            std::cout << ":)\tDluzsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        }
        else {
            std::cout << ":)\tKrotsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) <<d << std::endl;
        }
    }
    else {
        if(a < c) {
            std::cout << ":O\tDluzsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        }
        else {
            std::cout << ":O\tKrotsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        }
    }
}


/*!
 * Konstruktor Rectanglea
 * Argumenty:
 *  4 wektory, gdzie kazdy reprezentuje wspolrzedne jednego wierzcholka
 * Zwraca:
 */

Rectangle::Rectangle(Vector a, Vector b, Vector c, Vector d) {
    this->Corners[0] = a;
    this->Corners[1] = b;
    this->Corners[2] = c;
    this->Corners[3] = d;
}



/*!
 * Realizuje zapis wspolrzednych wierzcholkow Rectanglea do pliku
 * Argumenty:
 *  *sNazwaPliku - wskaznik do pliku, w ktorym zostana zapisane wspolrzedne
 * Zwraca:
 *  Prada jesli zapis sie powiodl
 *  Falsz jesli zapis sie nie powiodl
 */

bool Rectangle::ZapisWspolrzednychDoPliku( const char *sNazwaPliku) {

    std::ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
        << ":(  nie powiodla sie." << std::endl;
    return false;
    }

    StrmPlikowy << *this;
    StrmPlikowy << this->Corners[0];

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}