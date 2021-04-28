#include "../tests/doctest/doctest.h"
#include "matrix.hh"

TEST_CASE("test konstruktora Matrix bezparametrycznego oraz przeciazenia operatora () dla odczytu") {
    Matrix test;
    CHECK((test(0, 0) == 0 && test(0, 1) == 0 && test(1, 0) == 0 && test(1, 1) == 0));
}

TEST_CASE("test konstruktora Matrix z parametrem") {
    double array[2][2] = {1, 2, 3, 4};
    Matrix test(array);
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(1, 0) == 3 && test(1, 1) == 4));
}

TEST_CASE("test przeciazenia operatora () dla wczytywania") {
    Matrix test;
    test(0, 0) = 1;
    test(0, 1) = 2;
    test(1, 0) = 3;
    test(1, 1) = 4;
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(1, 0) == 3 && test(1, 1) == 4));
}

TEST_CASE("test przeciazenia operatora *") {
    double array[2] = {2, 4}, array2[2][2] = {1, 2, 3, 4};
    Vector v1(array), v2;
    Matrix test(array2);
    v2 = test * v1;
    CHECK((v2[0] == 10 && v2[1] == 22));
}

TEST_CASE("test przeciazenia operatora +") {
    double array1[2][2] = {1, 2, 3, 4}, array2[2][2] = {5, 6, 7, 8};
    Matrix test1(array1), test2(array2), result;
    result = test1 + test2;
    CHECK((result(0, 0) == 6 && result(0, 1) == 8 && result(1, 0) == 10 && result(1, 1) == 12));
}

TEST_CASE("test przeciazenia operatora >>") {
    Matrix test;
    std::istringstream in("1 2 3 4");
    in >> test;
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(1, 0) == 3 && test(1, 1) == 4));
}

TEST_CASE("test przeciazenia operatora >> dla bledu") {
    Matrix test;
    std::istringstream in("o r t m");
    WARN_THROWS(in >> test);
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[2][2] = {1, 2, 3, 4};
    Matrix test(array);
    std::ostringstream out;
    out << test;
    CHECK("| 1 | | 2 | | 3 | | 4 | " == out.str());
}

TEST_CASE("test metody RotationMatrix") {
    Matrix test;
    test.RotationMatrix(90);
    CHECK(((test(0, 0) >= 0 - 0.0000000001 && test(0, 0) <= 0 + 0.0000000001 && test(0, 1) == -1 && test(1, 0) == 1 && test(1, 1) >= 0 - 0,0000000001 && test(1, 1) <= 0 + 0,0000000001)));
}

TEST_CASE("test przeciazenia operatora () dla odczytu z bledem") {
    double array2[2][2] = {1, 2, 3, 4};
    Matrix test(array2);
    std::ostringstream out;
    WARN_THROWS(out << test(10, -15));
}

TEST_CASE("test przeciazenia operatora () dla wczytywania z bledem") {
    Matrix test;
    WARN_THROWS(test(10, -15) = 5);
}

TEST_CASE("test metody Determinant") {
    double array2[2][2] = {1, 2, 3, 4}, det;
    Matrix test(array2);
    det = test.Determinant();
    CHECK(det == -2);
}

TEST_CASE("test metody Determinant z bledem") {
    double array2[2][2] = {0, 2, 3, 4};
    Matrix test(array2);
    WARN_THROWS(test.Determinant());
}
