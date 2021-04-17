#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector.hh"
#include "matrix.hh"

#define REC 4

class Rectangle {
  Vector Corners[REC];
  public:
    Rectangle Translation(Vector);
    Rectangle Rotation(double, int);
    void Sides();
    Rectangle(Vector, Vector, Vector, Vector);
    Rectangle();
    bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku);
    const Vector &operator [] (int index) const;
    Vector &operator [] (int index);
};

std::ostream& operator << (std::ostream &Strm, const Rectangle &Pr);
std::istream& operator >> (std::istream &Strm, Rectangle &Pr);


#endif