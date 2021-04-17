#include "../tests/doctest/doctest.h"
#include "rectangle.hh"

TEST_CASE("test konstruktora Rectangle z parametrami") {
    double a1[2] = {1, 1}, a2[2] = {10, 1}, a3[2] = {10, 20}, a4[2] = {1, 20};
    Vector v1(a1), v2(a2), v3(a3), v4(a4);
    Rectangle Rec(v1, v2, v3, v4);
    CHECK(((Rec[0][0] == 1) && (Rec[0][1] == 1) && (Rec[1][0] == 10) && (Rec[1][1] == 1) && (Rec[2][0] == 10) && (Rec[2][1] == 20) && (Rec[3][0] == 1) && (Rec[3][1] == 20)));
}

TEST_CASE("test przeciazenia operatora <<") {
    double a1[2] = {1, 1}, a2[2] = {10, 1}, a3[2] = {10, 20}, a4[2] = {1, 20};
    Vector v1(a1), v2(a2), v3(a3), v4(a4);
    Rectangle Rec(v1, v2, v3, v4);
    std::ostringstream out;
    out << Rec;
    CHECK("1.0000000000 1.0000000000 \n10.0000000000 1.0000000000 \n10.0000000000 20.0000000000 \n1.0000000000 20.0000000000 \n" == out.str());
}

TEST_CASE("test metody Translation") {
    double a1[2] = {1, 1}, a2[2] = {10, 1}, a3[2] = {10, 20}, a4[2] = {1, 20}, a5[2] = {10, 20};
    Vector v1(a1), v2(a2), v3(a3), v4(a4), v5(a5);
    Rectangle Rec(v1, v2, v3, v4);
    Rec.Translation(v5);
    CHECK(((Rec[0][0] == 11) && (Rec[0][1] == 21) && (Rec[1][0] == 20) && (Rec[1][1] == 21) && (Rec[2][0] == 20) && (Rec[2][1] == 40) && (Rec[3][0] == 11) && (Rec[3][1] == 40)));
}

TEST_CASE("test metody Rotation") {
    double a1[2] = {1, 1}, a2[2] = {10, 1}, a3[2] = {10, 20}, a4[2] = {1, 20};
    Vector v1(a1), v2(a2), v3(a3), v4(a4);
    Rectangle Rec(v1, v2, v3, v4);
    Rec.Rotation(180, 1);
    CHECK(((Rec[0][0] >= -1-0.0000000001) && (Rec[0][1] >= -1-0.0000000001) && (Rec[1][0] >= -10-0.0000000001) && (Rec[1][1] >= -1-0.0000000001) && (Rec[2][0] >= -10-0.0000000001) && (Rec[2][1] >= -20-0.0000000001) && (Rec[3][0] >= -1-0.0000000001) && (Rec[3][1] >= -20-0.0000000001)));
}

