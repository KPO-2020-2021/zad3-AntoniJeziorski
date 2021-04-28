#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector.hh"
#include "matrix.hh"

#define REC 4

class Rectangle {

  Vector Corners[REC]; // Tablica 4 wektorow reprezentujaca wierzcholki prostokata

  public:

    Rectangle Translation(Vector); // Metoda translacji

    Rectangle Rotation(double, int); // Metoda obrotu

    void Sides() const; // Metoda sprawdzajaca boki

    Rectangle(Vector, Vector, Vector, Vector); // Konstruktor parametryczny

    Rectangle(); // Konstruktor bezparametryczny

    bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku); // Metoda zapisu do pliku

    const Vector &operator [] (int index) const; // Operator indeksujacy dla odczytu

    Vector &operator [] (int index); // Operator indeksujacy dla zapisu
};

std::ostream& operator << (std::ostream &Strm, const Rectangle &Pr); // Operator bitowy <<

std::istream& operator >> (std::istream &Strm, Rectangle &Pr); // Operator bitowy >>

