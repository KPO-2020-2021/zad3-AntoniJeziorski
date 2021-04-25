#include "../tests/doctest/doctest.h"
#include "vector.hh"

TEST_CASE("test konstruktora Vector bezparametrycznego")  {
    Vector vec;
    CHECK((vec[0] == 0 && vec[1] == 0));
}

TEST_CASE("Test konstruktora Vector z parametrem") {
    double array[2] = {4,5};
    Vector vec(array);
    CHECK(((vec[0] == 4) && (vec[1] == 5)));
}

TEST_CASE("test przeciazenia operatora [] dla odczytu") {
    double array[2] = {4 ,5};
    Vector vec(array);
    std::ostringstream out;
    out << vec[0] << " " << vec[1];
    std::cout << out.str();
    CHECK("4 5" == out.str());
}

TEST_CASE("test przeciazenia operatora [] dla zapisu") {
    Vector vec;
    vec[0] = 4;
    vec[1] = 5;
    std::ostringstream out;
    out << vec[0] << " " << vec[1];
    std::cout << out.str();
    CHECK("4 5" == out.str());
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[2] = {4,5};
    Vector vec(array);
    std::ostringstream out;
    out << vec;
    std::cout << out.str();
    CHECK("4.0000000000 5.0000000000 " == out.str());
}

TEST_CASE("test przeciazenia operatora >>") {
    Vector vec;
    std::istringstream in("4 5");
    in >> vec;
    CHECK((vec[0] == 4 && vec[1] == 5));
}

TEST_CASE("test przeciazenia operatora +") {
    double a1[2] = {4, 5}, a2[2] = {2, 3};
    Vector v1(a1), v2(a2), v3;
    v3 = v1 + v2;
    CHECK((v3[0] == 6 && v3[1] == 8));
}

TEST_CASE("test przeciazenia operatora -") {
    double a1[2] = {4, 5}, a2[2] = {2, 3};
    Vector v1(a1), v2(a2), v3;
    v3 = v1 - v2;
    CHECK((v3[0] == 2 && v3[1] == 2));
}

TEST_CASE("test przeciazenia operatora *") {
    double a1[2] = {4, 5}, a2 = 2;
    Vector v1(a1), v2;
    v2 = v1 * a2;
    CHECK((v2[0] == 8 && v2[1] == 10));
}

TEST_CASE("test przeciazenia operatora /") {
    double a1[2] = {4, 5}, a2 = 2;
    Vector v1(a1), v2;
    v2 = v1 / a2;
    CHECK((v2[0] == 2 && v2[1] == 2.5));
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[2] = {4,5};
    Vector vec(array);
    std::ostringstream out;
    out << vec;
    std::cout << out.str();
    CHECK("4.0000000000 5.0000000000 " == out.str());
}

TEST_CASE("test przeciazenia operatora >> dla bledu") {
    Vector vec;
    std::istringstream in("o #");
    WARN_THROWS(in >> vec);
}

TEST_CASE("test przeciazenia operatora [] dla wczytywania z bledem") {
    Vector vec;
    WARN_THROWS(vec[-21] = 1);
}

TEST_CASE("test przeciazenia operatora [] dla odczytu z bledem") {
    double array[2] = {4 ,5};
    Vector vec(array);
    std::ostringstream out;
    WARN_THROWS(out << vec[-10]);
}

TEST_CASE("test dzielenia wektora przez 0") {
    double array[2] = {4 ,5};
    Vector vec(array);
    double a = 0;
    WARN_THROWS(vec/a);
}