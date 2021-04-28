

#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Matrix {

double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);           // Operator dodawania macierzy

    double  &operator () (unsigned int row, unsigned int column);     // Operator funkcyjny dla odczytu
    
    const double &operator () (unsigned int row, unsigned int column) const; // operator funkcyjny dla zapisu

    Matrix RotationMatrix(double);  // Metoda tworzaca macierz obrotu

    double Determinant() const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);  // Operator bitowy >>

std::ostream &operator<<(std::ostream &out, Matrix const &mat); // Operator bitowy <<


