#include "rectangle.hh"

/*!
 * Przeciazenie operator indeksujacego dla odczytu
 * Argumenty:
 *      index - numer miejsca w tablicy
 * Zwraca:
 *      Wektor reprezentujacy jeden z wierzcholkow jako stala
 */



const Vector &Rectangle::operator [] (int index) const {
    if (index < 0 || index >= REC) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return Corners[index];
}

/*!
 * Przeciazenie operator indeksujacego dla zapisu
 * Argumenty:
 *      index - numer miejsca w tablicy
 * Zwraca:
 *      Wektor reprezentujacy jeden z wierzcholkow
 */


Vector &Rectangle::operator[](int index) {
    return const_cast<Vector &>(const_cast<const Rectangle *>(this)->operator[](index));
}





/*!
 * Przeciazenie operatora bitowego dla wyswietladnia prostokata
 * Argumenty:
 *  &Strm - referencja do strumienia wyjsciowego
 *  &Pr - prostokat, ktory zostanie wyswietlony
 * Zwraca:
 *  Strumien wyjsciowy z prostokatem
 */

std::ostream& operator << (std::ostream &Strm, const Rectangle &Pr) {
    for(int i=0; i < REC; i++) {
        Strm << Pr[i] << std::endl;
    }
    return Strm;
}



/*!
 * Przeciazenie operatora bitowego dla wczytywania prostokata
 * Argumenty:
 *  &Strm - referencja do strumienia wejsciowego
 *  &Pr -  referencja do wprowadzanego prostokata
 * Zwraca:
 *  Strumien wejsciowy z prostokatem
 */

std::istream& operator >> (std::istream &Strm, Rectangle &Pr) {
    for(int i=0; i < REC; i++) {
        Strm >> Pr[i];
    }
    return Strm;
}



/*!
 * Realizuje translacje prostokata o zadany wektor
 * Argumenty:
 *  vector - wektor, o jaki ma zostac wykonana translacja
 * Zwraca:
 *  Prostokat po przesunieciu o zadany wektor
 */

Rectangle Rectangle::Translation(Vector vector) {
    for(int i=0; i<REC; i++) {
        this->Corners[i] = this->Corners[i] + vector;
    }
    return *this;
}




/*!
 * Realizuje obrot Rectanglea wokol poczatku ukladu wspolrzednych
 * o zadany kat podana ilosc razy
 * Argumenty:
 *  angle - kat o jaki zostanie wykonany obrot
 *  amount - ilosc obrotow
 * Zwraca:
 *  Prostokat po wykonaniu obrotu
 */

Rectangle Rectangle::Rotation(double angle, int amount) {
    Matrix Rotation;
    Rotation.RotationMatrix(angle);
    for(int j=0; j < amount; j++){
        for(int i=0; i<REC; i++) {
            this->Corners[i] = Rotation * this->Corners[i];
        }
    }
    return *this;
}


/*!
 * Wyswietla dlugosci bokow prostokata oraz sprawdza, czy przeciwne boki sa tej samej dlugosci
 * Argumenty:
 *  this - sprawdzany prostokat
 * Zwraca:
 */

void Rectangle::Sides() const {
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
 * Konstruktor parametryczny prostokata
 * Argumenty:
 *  4 wektory, gdzie kazdy reprezentuje wspolrzedne jednego wierzcholka
 * Zwraca:
 *  Prostokat o zadanych wierzcholkach
 */

Rectangle::Rectangle(Vector a, Vector b, Vector c, Vector d) {
    this->Corners[0] = a;
    this->Corners[1] = b;
    this->Corners[2] = c;
    this->Corners[3] = d;
}



/*!
 * Konstruktor bezparametryczny prostokata
 * Argumenty:
 * Zwraca:
 *  Tablice 4 wektorow z ktorych kazdy jest wypelniony zerami
 */

Rectangle::Rectangle() {
    this->Corners[0] = 0;
    this->Corners[1] = 0;
    this->Corners[2] = 0;
    this->Corners[3] = 0;
}



/*!
 * Realizuje zapis wspolrzednych wierzcholkow prostokata do pliku
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
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
        return false;
    }

    StrmPlikowy << *this;
    StrmPlikowy << this->Corners[0];

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
