#include "matrix.hh"

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    if((SIZE < 0) || (SIZE > 2)) {
        throw std::runtime_error("Niepoprawny rozmiar macierzy");
    }
    else {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                value[i][j] = tmp[i][j];
            }
        }
    }
    
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - Matrix, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                         |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem"); 
    }

    if (column >= SIZE) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor Matrixy                                                           |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - Matrix, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Matrix - iloczyn dwóch podanych macierzy.                             |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - Matrix.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    if(in.fail())
        throw std::runtime_error("Niepoprawny typ zmiennej w macierzy");
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - Matrix.                                                         |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}


/*!
 * Metoda tworzaca macierz obrotu
 * Argumenty:
 *      this - macierz, ktora zostanie wypelniona odpowiednimi wartosciami
 *      angle - kat o jaki chcemy obrocic prostokat
 */


Matrix Matrix::RotationMatrix(double angle) {
    this->value[0][0] = cos(angle*M_PI/180);
    this->value[0][1] = -sin(angle*M_PI/180);
    this->value[1][0] = sin(angle*M_PI/180);
    this->value[1][1] = cos(angle*M_PI/180);
    return *this;
}