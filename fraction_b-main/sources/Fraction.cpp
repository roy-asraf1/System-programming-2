
#include "Fraction.hpp"

namespace ariel
{
    // default constructor
    Fraction ::Fraction()
    {
        this->Numerator = 0;
        this->Denominator = 1;
    }
    // parameterized constructor (regular)
    Fraction ::Fraction(int num, int denom)
    {
        if (denom == 0)
        {
            throw std ::invalid_argument("denominator cannot be zero \n");
        }
        const int gcd = mygcd(num, denom);
        Numerator = num / gcd;
        Denominator = denom / gcd;
        if (Denominator < 0 && Numerator > 0) {
            Numerator = -Numerator;
            Denominator = -Denominator;
        }
    }

   Fraction::Fraction(float numa) {
    const int max = 1000;
    const int gcd = mygcd(static_cast<int>(numa * max), max);
    Numerator = static_cast<int>(numa * max) / gcd;
    Denominator = max / gcd;
    }

    int Fraction::mygcd(long long a, long long b) const {
        while (b != 0) {
            const long long temp = b;
            b = a % b;
            a = temp;
        }
        return static_cast<int>(a);
    }

    void Fraction ::setNumerator(int Numerator)
    {
        this->Numerator = Numerator;
    }
    void Fraction :: setDenomirator(int denumirator)
    {
        if (denumirator == 0)
        {
            throw std ::invalid_argument("denominator cannot be zero \n");
        }
        else{
            this->Denominator = denumirator;
        }
    }
    //operator+
    const Fraction Fraction::operator+(const Fraction& other) const {
        long long newNumerator = static_cast<long long>(Numerator) * other.Denominator + static_cast<long long>(other.Numerator) * Denominator;
        long long newDenominator = static_cast<long long>(Denominator) * other.Denominator;
        if (newNumerator < std::numeric_limits<int>::min() || newNumerator > std::numeric_limits<int>::max() || newDenominator < std::numeric_limits<int>::min() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("integer overflow");
        }
        return Fraction(static_cast<int>(newNumerator), static_cast<int>(newDenominator));
    }

    const Fraction operator+(const float& fractNum,const Fraction& other){
        Fraction fract(fractNum);
        int newNum = (fract.getNumerator() * other.getDenominator()) + (other.getNumerator() * fract.getDenominator());
        int newDen = fract.getDenominator() * other.getDenominator();
        return Fraction(newNum,newDen);
    }


    const Fraction Fraction::operator+(const float &fraction) const
    {
        return Fraction(fraction) + (*this);
    }
    //operator-
       Fraction Fraction::operator-(const Fraction& other)const{
        int gcd = mygcd(Numerator, Denominator);

        long long newNuminator = (long long)(this->Numerator * other.getDenominator()) - (other.getNumerator() * this->Denominator);
        long long newDenominator = (long long)(this->Denominator * other.getDenominator());
        newNuminator = newNuminator/gcd;
        newDenominator = newDenominator/gcd;

        if (newNuminator > std::numeric_limits<int>::max() || newNuminator < std::numeric_limits<int>::min() || newDenominator > std::numeric_limits<int>::max() || newDenominator < std::numeric_limits<int>::min())
        {
            throw std::overflow_error("got overflow");
        }

        int num = (this->Numerator * other.getDenominator()) - (other.getNumerator() * this->Denominator);
        int den = (this->Denominator * other.getDenominator());
        return Fraction(num, den);

    }

    Fraction Fraction::operator-(float fractNum)const{
        Fraction result(fractNum);
        return *this - result;
    }

    Fraction operator-(float fractNum, const Fraction& other){
        Fraction fract(fractNum);
        int newNuminator = (fract.getNumerator() * other.getDenominator()) - (other.getNumerator() * fract.getDenominator());
        int newDenominator = fract.getDenominator() * other.getDenominator();
        return Fraction(newNuminator,newDenominator);
    }
    //operator*
    Fraction Fraction::operator*(const Fraction& other) const {
        const long long newNumerator = static_cast<long long>(Numerator) * other.getNumerator();
        const long long newDenominator = static_cast<long long>(Denominator) * other.getDenominator();
        if (newNumerator < std::numeric_limits<int>::min() || newNumerator > std::numeric_limits<int>::max() || newDenominator < std::numeric_limits<int>::min() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("got overflow");
        }
        return Fraction(static_cast<int>(newNumerator), static_cast<int>(newDenominator));
    }
    Fraction Fraction::operator*(float f) const {
        const Fraction result(f);
        return (*this) * result;
    }

    const Fraction operator*(float f, const Fraction &other){
       Fraction result(f);
       return result * (other);
    }
    //operator/
    const Fraction Fraction::operator/(const Fraction& other)const{
        if (other.getNumerator() == 0) {
        throw std::overflow_error("denominator cannot be zero");
        }
        long long newNumerator = static_cast<long long>(Numerator) * other.getDenominator();
        long long newDenominator = static_cast<long long>(Denominator) * other.getNumerator();
        if (newNumerator < std::numeric_limits<int>::min() || newNumerator > std::numeric_limits<int>::max() || newDenominator < std::numeric_limits<int>::min() || newDenominator > std::numeric_limits<int>::max()) {
            throw std::overflow_error("got overflow");
        }
        return Fraction(static_cast<int>(newNumerator), static_cast<int>(newDenominator));
    }

    const Fraction Fraction::operator/(float f)const{
        if (f == 0){
            throw std::overflow_error("denominator cannot be zero");
        }
        Fraction surce = *this;
        Fraction res(f);
        return surce / res;
    }

    const Fraction operator/(float fractNum, const Fraction &other){
        if (other.getDenominator() == 0) {
            throw std::overflow_error("denominator cannot be zero");
        }
        Fraction res(fractNum);
        return res / other;
    }

    //operator<
    const bool Fraction::operator<(const Fraction& other) const {
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        float otherFraction = static_cast<float>(other.getNumerator()) / (other.getDenominator());
        return thisFraction < otherFraction;   
    }

    const bool Fraction::operator<(float fractNum) const{
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        return thisFraction < fractNum;
    }
    const bool operator<(float floatValue, const Fraction& fraction){
        float otherFraction = static_cast<float>(fraction.getNumerator()) / (fraction.getDenominator());
        return floatValue < otherFraction;
    }
    //operator>
    const bool Fraction::operator>(const Fraction& other) const {
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        float otherFraction = static_cast<float>(other.getNumerator()) / (other.getDenominator());
        return thisFraction > otherFraction;
    }

    const bool Fraction::operator>(float floatValue)const{
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        return thisFraction > floatValue;
    }

    const bool operator>(float fractNum, const Fraction& fraction){
        float otherFraction = static_cast<float>(fraction.getNumerator()) / (fraction.getDenominator());
        return fractNum > otherFraction;
    }
    //operator==
    const bool operator==(const Fraction& left, const Fraction& right){
        float leftFraction = (static_cast<float>(left.getNumerator()) / static_cast<float>(left.getDenominator()));
        float rightFraction = (static_cast<float>(right.getNumerator()) / static_cast<float>(right.getDenominator()));
        return leftFraction == rightFraction;
    }
    const bool operator==(const Fraction& fraction, float floatValue){
        float leftFraction = (static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator()));
        return leftFraction == floatValue;
    }
    const bool operator==(float floatValue, const Fraction& fraction){
        float rightFraction = (static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator()));
        return floatValue == rightFraction;
    }
    //operator<=
    const bool Fraction::operator<=(const Fraction& other) const {
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        float otherFraction = static_cast<float>(other.getNumerator()) / (other.getDenominator());
        return thisFraction <= otherFraction;
    }

    const bool Fraction::operator<=(float floatValue)const{
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        return thisFraction <= floatValue;
    }

    const bool operator<=(float floatValue, const Fraction& fraction){
        float otherFraction = static_cast<float>(fraction.getNumerator()) / (fraction.getDenominator());
        return floatValue <= otherFraction;
}
    //operator>=
    const bool Fraction::operator>=(const Fraction& other) const {
        float thisFraction = static_cast<float>(this->Numerator) / (this->Denominator);
        float otherFraction = static_cast<float>(other.getNumerator()) / (other.getDenominator());
        return thisFraction >= otherFraction; 
          }

    const bool Fraction::operator>=(float fractNum)const{
        float thisValue = static_cast<float>(this->Numerator) / (this->Denominator);
        return thisValue >= fractNum;
    }

    const bool operator>=(float fractNum, const Fraction& other){
        float otherValue = static_cast<float>(other.getNumerator()) / (other.getDenominator());
        return fractNum >= otherValue;
    }


    //operator++
    Fraction& Fraction::operator++(){
        this->setNumerator(this->getNumerator() + this->getDenominator());
        return *this;
    }

 
    Fraction Fraction::operator++(int) {
        Fraction a = *this;
        this->setNumerator(this->getNumerator() + this->getDenominator());
        return a;
    }

    //operator--
    Fraction& Fraction::operator--(){
        this->setNumerator(this->getNumerator() - this->getDenominator());
        return *this;
    }

 
    Fraction Fraction::operator--(int) {
        Fraction a = *this;
        this->setNumerator(this->getNumerator() - this->getDenominator());
        return a;
    }

   
    std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
    {
        output << fraction.getNumerator() << "/" << fraction.getDenominator();
        return output;
    }

    std::istream& operator>>(std::istream& input, Fraction& fraction)
    {
        int Numerator, Denominator;
        if (!((input) >> Numerator >> Denominator)) {throw runtime_error("Invalid input for Fraction");}
        if (Denominator == 0) throw runtime_error("denominator cannot be zero");

        fraction = Fraction(Numerator, Denominator);
        return input;
    }
}
