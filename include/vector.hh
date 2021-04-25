#ifndef VECTOR_HH
#define VECTOR_HH

#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>



class Vector {

    double size[SIZE];     //Tablica wektora

    public:

        Vector(); // Konstruktor bezparametryczny

        Vector(double [SIZE]); // Konstruktor parametryczny

        Vector operator + (const Vector &v); // Operator dodawania wektorow

        Vector operator - (const Vector &v); // Operator odejmowania wektorow

        Vector operator * (const double &tmp); // Operator mnozenia wektora razy double

        Vector operator / (const double &tmp); // Operator dzielenia wektora przez double

        const double &operator [] (int index) const; // Operator indeksujacy dla odczytu

        double &operator [] (int index); // Operator indeksujacy dla zapisu
};

std::ostream &operator << (std::ostream &out, Vector const &tmp); // Operator bitowy <<

std::istream &operator >> (std::istream &in, Vector &tmp); // Operator bitowy >>



#endif
