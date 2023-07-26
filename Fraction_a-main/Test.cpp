#include "doctest.h"
#include <iostream>
#include "sources/Fraction.hpp"
#include <stdexcept>
#include <ctime>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>


using namespace std;
using namespace ariel;



TEST_CASE("throws") {
    cout << "starting the test:" << endl;
    Fraction f1(1, 2);
    Fraction f2(0.5);
    CHECK_NOTHROW(Fraction(1, 2));
    CHECK_NOTHROW(Fraction(0.5));
    CHECK_NOTHROW(Fraction());
    CHECK_NOTHROW(f1 / f2);
    CHECK_NOTHROW(++f1);
    CHECK_NOTHROW(--f1);
    
}
TEST_CASE("THE CONSTUCTORS:")
{
    //default 
    Fraction fraction1;
    Fraction fraction2(3, 4);
    Fraction fraction3(0.5);
    Fraction fraction4(fraction2);
    
    CHECK(fraction1.getNumerator() == 0);
    CHECK(fraction1.getDenominator() == 0);

    cout << "check to ints:" << endl;
    CHECK(fraction2.getNumerator() == 3);
    CHECK(fraction2.getDenominator() == 4);

    cout << "check one double:" << endl;
    CHECK(fraction3.getNumerator() == 1);
    CHECK(fraction3.getDenominator() == 2);

    cout << "check copy CONSTUCTORS:" << endl;
    CHECK(fraction4.getNumerator() == 3);
    CHECK(fraction4.getDenominator() == 4);
}

TEST_CASE("Exceptions and handle with them"){
cout << "check for invalid denominator" << endl;
CHECK_THROWS_AS(Fraction(1, 0), invalid_argument);

cout << "check for division by zero" << endl;
Fraction fraction1(1, 2);
Fraction fraction2(0);
CHECK_THROWS_AS(fraction1 / fraction2, invalid_argument);

//more of 3 digits
CHECK_THROWS(Fraction(0.1111)); 
CHECK_THROWS(Fraction(0.11111));

cout << "check for input stream" << endl;
Fraction fraction3;
std::stringstream ss("1/0");
CHECK_THROWS_AS(ss >> fraction3, invalid_argument);

cout << "check foroutput  stream" << endl;
Fraction fraction4(1, 0);
std::stringstream ss2;
CHECK_THROWS_AS(ss2 << fraction4, invalid_argument);
//invalid /0
CHECK_THROWS(Fraction(1,0)); 

}

TEST_CASE("VALID ANSWERS,OPERATORS AND ALSO THERE IS NO INFINITE LOOP:"){
    clock_t start, end;
    start = clock();
    Fraction fraction0(2,4);
    Fraction fraction1(1, 2);
    Fraction fraction2(3, 4);
    Fraction fraction3 = fraction1 + fraction2;
    Fraction fraction4 = fraction1 - fraction2;
    Fraction fraction5 = fraction1 * fraction2;
    Fraction fraction6 = fraction1 / fraction2;

    CHECK(fraction3.getNumerator() == 5);
    CHECK(fraction3.getDenominator() == 4);
    CHECK(fraction4.getNumerator() == -1);
    CHECK(fraction4.getDenominator() == 4);
    CHECK(fraction5.getNumerator() == 3);
    CHECK(fraction5.getDenominator() == 8);
    CHECK(fraction6.getNumerator() == 2);
    CHECK(fraction6.getDenominator() == 3);

    CHECK(fraction2 > fraction1);
    CHECK(fraction1 < fraction2);
    CHECK(fraction2 >= fraction2);
    CHECK(fraction0 >= fraction2);
    CHECK(fraction1 <= fraction1);
    
    // fraction become simplified
    Fraction valid(2,4);  
    CHECK(valid.getNumerator() == 1);
    CHECK(valid.getDenominator() == 2);
    
    cout << "check for some loop" << endl;
    end = clock();
    double timeTotal = double(end - start) / CLOCKS_PER_SEC;
    CHECK(timeTotal < 5.0);
}

TEST_CASE("increase and decrese "){
    Fraction fraction1(2, 3);
    fraction1++;
    CHECK(fraction1.getNumerator() == 5);
    CHECK(fraction1.getDenominator() == 3);
    fraction1--;
    CHECK(fraction1.getNumerator() == 2);
    CHECK(fraction1.getDenominator() == 3);
}


TEST_CASE("IO Operators")
{
    Fraction fraction1(3, 4);
    Fraction fraction2;
    std::stringstream ss;
    std::stringstream ss2("1/2");
    ss << fraction1;
    ss2 >> fraction2;
    CHECK(ss.str() == "3/4");
    CHECK_NOTHROW(ss << fraction1);
    CHECK(fraction2.getNumerator() == 1);
    CHECK(fraction2.getDenominator() == 2);

}
TEST_CASE("ARITHMETIC OPERATORS"){
    Fraction fraction1(1, 3);
    Fraction fraction2(2, 3);
    Fraction fraction3(1, 2);
    Fraction fraction4(2, 5);
    Fraction fraction5(7, 8);
    
    cout << "check for operator+" << endl;
    Fraction res1 = fraction1 + fraction2;
    Fraction res2 = fraction3 + fraction4;
    Fraction res3 = fraction2 + fraction5;
    CHECK(res1.getNumerator() == 1);
    CHECK(res1.getDenominator() == 1);
    CHECK(res2.getNumerator() == 9);
    CHECK(res2.getDenominator() == 10);
    CHECK(res3.getNumerator() == 17);
    CHECK(res3.getDenominator() == 8);

    
    cout << "check for operator-" << endl;
    Fraction res4 = fraction1 - fraction2;
    Fraction res5 = fraction3 - fraction4;
    Fraction res6 = fraction5 - fraction2;
    CHECK(res4.getNumerator() == -1);
    CHECK(res4.getDenominator() == 3);
    CHECK(res5.getNumerator() == 1);
    CHECK(res5.getDenominator() == 10);
    CHECK(res6.getNumerator() == 1);
    CHECK(res6.getDenominator() == 24);

    cout << "check for multiplication operator*" << endl;
    Fraction res7 = fraction1 * fraction2;
    Fraction res8 = fraction3 * fraction4;
    Fraction res9 = fraction2 * fraction5;
    CHECK(res7.getNumerator() == 2);
    CHECK(res7.getDenominator() == 9);
    CHECK(res8.getNumerator() == 1);
    CHECK(res8.getDenominator() == 5);
    CHECK(res9.getNumerator() == 7);
    CHECK(res9.getDenominator() == 12);

    cout << "check for divison operator/" << endl;
    Fraction res10 = fraction1 / fraction2;
    Fraction res11 = fraction3 / fraction4;
    Fraction res12 = fraction5 / fraction2;
    CHECK(res10.getNumerator() == 1);
    CHECK(res10.getDenominator() == 2);
    CHECK(res11.getNumerator() == 5);
    CHECK(res11.getDenominator() == 4);
    CHECK(res12.getNumerator() == 7);
    CHECK(res12.getDenominator() == 12);
}

TEST_CASE("Equality Operators"){
    Fraction fraction1(1, 2);
    Fraction fraction2(2, 4);
    Fraction fraction3(3, 4);
    Fraction fraction4(1, 3);

   
    cout << "check for equality operator ==" << endl;
    CHECK(fraction1 == fraction2);
    CHECK(fraction2 == fraction1);
    CHECK_FALSE(fraction1 == fraction3);
    CHECK_FALSE(fraction3 == fraction1);
    CHECK_FALSE(fraction1 == fraction4);
    CHECK_FALSE(fraction4 == fraction1);

  
    cout << "check for inequality operator !=" << endl;
    CHECK_FALSE(fraction1 != fraction2);
    CHECK_FALSE(fraction2 != fraction1);
    CHECK(fraction1 != fraction3);
    CHECK(fraction3 != fraction1);
    CHECK(fraction1 != fraction4);
    CHECK(fraction4 != fraction1);
}

TEST_CASE("Assignment Operators"){
    Fraction fraction1(1, 2);
    Fraction fraction2(2, 4);
    Fraction fraction3(3, 4);
    Fraction fraction4(1, 3);

    
    cout << "check for assignment operator ==" << endl;
    fraction1 = fraction3;
    fraction2 = fraction4;
    CHECK(fraction1.getNumerator() == 3);
    CHECK(fraction1.getDenominator()==4);
    
    CHECK(fraction2.getNumerator() == 1);
}




