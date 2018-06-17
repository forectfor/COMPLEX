#include "catch.hpp"
#include "complex.hpp"

SCENARIO("complex new without param","[new without param]"){
    Complex complex;
    REQUIRE(complex.real() == 0);
    REQUIRE(complex.imaginary() == 0);
}

SCENARIO("complex new with pram","[new with param]"){
    Complex complex(2, 2);
    REQUIRE(complex.real() == 2);
    REQUIRE(complex.imaginary() == 2);
}

SCENARIO("complex copy","[copy]"){
    Complex complex1(2, 2);
    Complex complex2(complex1);
    REQUIRE(complex2.real() == 2);
    REQUIRE(complex2.imaginary() == 2);
}

SCENARIO("complex sum","[sum]"){
    Complex complex1(2, 2), complex2(3, 3), complex3(5, 5);
    REQUIRE((complex1.add(complex2) == complex3) == true);
}

SCENARIO("complex sub","[sub]"){
    Complex complex1(3, 3), complex2(2, 2), complex3(1, 1);
    REQUIRE((complex1.sub(complex2) == complex3) == true);
}

SCENARIO("complex mul ", "[mul]") {
    Complex complex1(2, 2), complex2;
    int numbers = 2;
    complex2 = complex1.mul(numbers);
    REQUIRE(complex2.real() == 4);
    REQUIRE(complex2.imaginary() == 4);
}

SCENARIO("complex div", "[div]") {
    Complex complex1(4, 4), complex2;
    int numbers = 2;
    complex2 = complex1.div(numbers);
    REQUIRE(complex2.real() == 2);
    REQUIRE(complex2.imaginary() == 2);
}

SCENARIO("complex operator*","[oper*]"){
    Complex complex1(1, 2), complex2(3, 4), complex3(-5, 10);
    REQUIRE((complex1*complex2 == complex3) == true);
}

SCENARIO("complex operator/","[oper/]"){
    Complex complex1(1, 2), complex2(3, 4), complex3(0.44, 0.08);
    REQUIRE((complex1/complex2 == complex3) == true);
}

SCENARIO("complex operator +=","[oper+=]"){
    Complex complex1(2, 2), complex2(3, 3), complex3(5, 5);
    complex1 += complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator -=","[oper-=]"){
    Complex complex1(3, 3), complex2(2, 2), complex3(1, 1);
    complex1 -= complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator *=","[oper-*=]"){
    Complex complex1(1, 2), complex2(3, 4), complex3(-5, 10);
    complex1 *= complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator /=","[oper/=]"){
    Complex complex1(1, 2), complex2(3, 4), complex3(0.44, 0.08);
    complex1 /= complex2;
    REQUIRE((complex1 == complex3) == true);
}

SCENARIO("complex operator =","[oper=]"){
    Complex complex1(2, 2), complex2(3, 3);
    complex1 = complex2;
    REQUIRE((complex1 == complex2) == true);
}

SCENARIO("complex operator ==","[oper==]"){
    Complex complex1(2, 2), complex2(2, 2);

    REQUIRE((complex1 == complex2) == true);
}
