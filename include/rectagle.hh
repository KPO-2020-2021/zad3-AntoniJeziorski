#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector.hh"
#include "matrix.hh"

#define REC 4

class Rectangle {
  friend std::ostream& operator << (std::ostream &Strm, const Rectangle &Pr);
  friend std::istream& operator >> (std::istream &Strm, Rectangle &Pr);
  Vector Corners[REC];
  public:
    Rectangle translacja(Vector);
    Rectangle obrot(double, int);
    void boki();
    Rectangle(Vector, Vector, Vector, Vector);
    bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku);
};

std::ostream& operator << (std::ostream &Strm, const Rectangle &Pr);
std::istream& operator >> (std::istream &Strm, Rectangle &Pr);


#endif