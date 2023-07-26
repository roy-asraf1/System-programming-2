#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>



using namespace std;
namespace ariel{

    class Fraction
    {
        private:
        int Numerator ;
        int Denominator;
        void reduce();
        
        public:
            Fraction(int Numerator, int Denominator);
            Fraction(float);
            Fraction();

            Fraction(const Fraction& other);
            ~Fraction();

            int getNumerator() const;
            int getDenominator() const;
            void setNumirator(int numirator);
            void setDenomirator(int denumirator);

            Fraction operator+( Fraction& other);
            Fraction operator-( Fraction& other);
            Fraction operator/( Fraction& other);
            Fraction operator*( Fraction& other);

            float operator+(float fractNum);
            float operator-(float fractNum);
            float operator*(float fractNum);
            friend Fraction operator*(float fractNum, const Fraction &frac);

            bool operator==(const Fraction& other) const;
            bool operator>(const Fraction& other) const ;
            bool operator<(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;

            Fraction operator++();
            Fraction operator++(int);
            Fraction operator--();
            Fraction operator--(int);
            
            friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    };
     
};
#endif
