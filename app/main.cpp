// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <unistd.h>

#include "exampleConfig.h"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include "../include/lacze_do_gnuplota.hh"




int main() {
    double X[2]={1,1}, Y[2]={50,1}, Z[2]={50,100}, T[2]={1,100}, angle, amount;
    Vector x(X), y(Y), z(Z), t(T), v;
    Rectangle Rec(x, y, z, t);   
    PzG::LaczeDoGNUPlota  Lacze;    // Ta zmienna jest potrzebna do wizualizacji
                                    // rysunku Prostokata
    char option = '0', animation = '0';

//-------------------------------------------------------
    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "Prostokat.dat"
    //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
    //  na dwa sposoby:
    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
    //
    //   2. Rysowane jako zbior punktow reRecezentowanych Reczez kwadraty,
    //      których połowa długości boku wynosi 2.
    //
    Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_2D);
    try {
        Rec.Sides();
        Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        if (!Rec.ZapisWspolrzednychDoPliku("../datasets/prostokat.dat")) return 1;
        while(option != 'k') {
            if(option == '0')
            {
                std::cout << "o - obrot prostokata o zadany kat" << std::endl;
                std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
                std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
                std::cout << "a - wyswietlanie animacj" << std::endl;
                std::cout << "m - wyswietl menu" << std::endl;
                std::cout << "k - koniec dzialania programu" << std:: endl;
            }
            std::cout << "Twoj wybor: " << std::endl;
            std::cin >> option;
            switch(option) {
                case 'k':
                    option = 'k'; break;
                case 'p':
                    
                    std::cout << "Podaj wspolrzedne wektora" << std::endl;
                    std::cin >> v;
                    Rec.Translation(v);
                    Rec.Sides();
                    if (!Rec.ZapisWspolrzednychDoPliku("../datasets/prostokat.dat")) return 1;
                    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                    break;
                case 'o':
                    
                    std::cout << "Podaj kat w stopniach oraz ilosc obrotow" << std::endl;
                    std::cin >> angle >> amount;
                    Rec.Rotation(angle, amount);
                    Rec.Sides();
                    if (!Rec.ZapisWspolrzednychDoPliku("../datasets/prostokat.dat")) return 1;
                    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                    break;
                case 'w':
                    std::cout << Rec; break;
                case 'm':
                    option = '0';
                    break; 
                case 'a':
                    std::cout << "Wybierz animacje :\n1. Animacja obrotu\n2. Animacja translacji" << std::endl;
                    std::cin >> animation;
                    switch(animation) {
                        case '1':
                            
                            std::cout << "Podaj kat w stopniach oraz ilosc obrotow" << std::endl;
                            std::cin >> angle >> amount;
                            for(int j=0; j < amount; j++) {
                                for(int i=0; i < FLOPS; i++) {
                                    Rec.Rotation(angle / FLOPS, 1);
                                    if (!Rec.ZapisWspolrzednychDoPliku("../datasets/prostokat.dat")) return 1;
                                    usleep(5000);
                                    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                                    usleep(5000);
                                }    
                            }
                            break;
                        case '2':
                            
                            std::cout << "Podaj wspolrzedne wektora" << std::endl;
                            std::cin >> v;
                            for(int i=0; i < FLOPS; i++) {
                                Rec.Translation(v/FLOPS);
                                if (!Rec.ZapisWspolrzednychDoPliku("../datasets/prostokat.dat")) return 1;
                                    usleep(5000);
                                    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                                    usleep(5000);
                            }
                            break;
                        default:
                            option = '0';
                            std::cerr << "!!! NIE MA TAKIEJ ANIMACJI !!!" << std::endl; break;
                    }
                    break;
                default:
                    option = '0';
                    std::cerr << "!!! NIEPOPRAWNA OPCJA !!!" << std::endl; break;
            }
        }
    }
    catch(std::runtime_error& e) {
        std::cerr << "Blad" << e.what() << "\n";
        exit(1);

    }
    return 0;
}

