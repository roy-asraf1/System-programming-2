

#include "Fraction.hpp" 
#include "iostream"
using namespace std;
 namespace ariel{

Fraction :: Fraction (int Numerator, int Denominator){
    this->Numerator =Numerator;
    this->Denominator=Denominator;
}
Fraction :: Fraction (float numa){
    this->Numerator =numa;
    this->Denominator=1;
}
Fraction ::Fraction (){
    this->Numerator =0;
    this->Denominator =1;
}
Fraction :: Fraction (const Fraction& copy):Numerator(copy.Numerator),Denominator(copy.Denominator){//copy constractor

}
Fraction :: ~Fraction(){

   

}
int Fraction :: getDenominator () const{
    return Denominator;
}
int Fraction :: getNumerator () const{
    return Numerator;
}


Fraction Fraction::operator+(Fraction& other){
    Fraction ans = Fraction(other.Numerator + Numerator, other.Denominator + Denominator);
    return ans;
}
float Fraction::operator+(float fractNumber){
    float end = (this->Numerator / this->Denominator) + fractNumber;
    return end;
}
Fraction Fraction::operator-(Fraction& other){
    int numerator = Numerator * other.Denominator - Denominator * other.Numerator;
    int denominator = Denominator * other.Denominator;
    return Fraction(numerator, denominator);
}
float Fraction::operator-(float fractNumber){
    float end = (this->Numerator / this->Denominator) - fractNumber;
    return end;
}
Fraction Fraction::operator/(Fraction& other){
    int numerator = Numerator * other.Denominator;
    int denominator = Denominator * other.Numerator;
    return Fraction(numerator, denominator);


}
Fraction Fraction::operator*(Fraction& other){
    int numerator = Numerator * other.Numerator;
    int denominator = Denominator * other.Denominator;
    return Fraction(numerator, denominator);

}
    float Fraction::operator*(float fractNumber){
        float end = (this->Numerator / this->Denominator) * fractNumber;
        return end;
}
Fraction operator*(float fractNum, const Fraction &frac){
    return Fraction();
}
bool Fraction::operator==(const Fraction& other) const { 
    if (other.Numerator==Numerator && other.Denominator==Denominator)
        return true;
    return false;
}

bool Fraction :: operator>(const Fraction& other)const{
    bool t =false;
    if( Numerator * other.Denominator > other.Numerator * Denominator)
        t=true;
    return t;
}
bool Fraction :: operator<(const Fraction& other)const{
    bool t =true;
    if( Numerator * other.Denominator < other.Numerator * Denominator)
        t=false;
    return t;
}

Fraction Fraction ::operator++(){
    Numerator += Denominator;
    return *this;
    
}
Fraction Fraction ::operator++(int){
    Numerator += Denominator;
    return *this;
    
}
Fraction Fraction ::operator--(){
    Numerator -= Denominator;
    return *this;
    
}
Fraction Fraction ::operator--(int){
    Numerator -= Denominator;
    return *this;
    
}

bool Fraction::operator>=(const Fraction& other) const {
    return Numerator * other.Denominator >= other.Numerator * Denominator;
}
bool Fraction :: operator<=(const Fraction& other)const{
    return Numerator * other.Denominator <= other.Numerator * Denominator;
}

    std::ostream& operator<<(std::ostream& outs, const Fraction& fraction) {
    
    return outs;
}
std::istream& operator>>(std::istream& ins, Fraction& fraction) {
    return ins;
}
void Fraction:: reduce() {
    cout << "start reduce" <<endl;
}
 }
