#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <limits>

using namespace std;
namespace ariel{

    class Fraction
    {
    private:
        int Numerator ;
        int Denominator;
        
    public:
            // parameterized  constructor
            Fraction(int, int);
            
            Fraction(float);
            // default constructor
            Fraction();
            
        
            const Fraction operator+(const float& )const;
            const Fraction operator+(const Fraction& )const;
            friend const Fraction operator+(const float& , const Fraction& );

            Fraction operator-(const Fraction& )const;
            Fraction operator-(float ) const;
            friend Fraction operator-(float , const Fraction& );

            Fraction operator*(const Fraction& )const;
            Fraction operator*(float )const;
            const friend Fraction operator*(float , const Fraction&);

            const Fraction operator/(const Fraction& )const;
            const Fraction operator/(float )const;
            const friend Fraction operator/(float , const Fraction& );


            const bool operator<(const Fraction&)const;
            const bool operator<(float )const;
            const friend bool operator<(float , const Fraction&);

            const bool operator>(const Fraction& )const;
            const bool operator>(float )const;
            const friend bool operator>(float , const Fraction& );

            const friend bool operator==(const Fraction& , const Fraction& );
            const friend bool operator==(const Fraction&  ,float );
            const friend bool operator==(float , const Fraction& );

            const bool operator<=(const Fraction& ) const;
            const bool operator<=(float ) const;
            const friend bool operator <=(float , const Fraction& );

            const bool operator>=(const Fraction& ) const;
            const bool operator>=(float ) const;
            const friend bool operator>=(float , const Fraction& );    

            Fraction& operator++();
            Fraction operator++(int);

            Fraction& operator--();
            Fraction operator--(int);
            
            friend std::ostream& operator<<(std::ostream& , const Fraction& );
            friend std::istream& operator>>(std::istream& , Fraction& );

            
            //methods without the operators
            int mygcd(long long numa, long long numb) const;  // greatest common divisor
            void dividebyTheGcd();
            void setNumerator(int numirator);
            void setDenomirator(int denumirator);
             void Factorization();


            int getNumerator() const {
            return this->Numerator;
            }

            int getDenominator() const
            {
                return this->Denominator;
            }
    };
     
};
#endif
