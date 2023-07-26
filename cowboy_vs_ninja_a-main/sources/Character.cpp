#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;


Character::Character(std::string name, const Point& point, int hitPoints) : Point(point), name(name), hitPoints(hitPoints)
{
}
Character& Character::operator=(const Character& other) {
    if (this == &other) {
        return *this;
    }

    // Copy the member variables
    this->Point::operator=(other);
    this->name = other.name;
    this->hitPoints = other.hitPoints;

    return *this;
}

bool Character:: isAlive(){
    return true;
}
double Character:: distance(Character* player){
    return 1.0;
}
void Character:: hit(int hit){

}
string Character:: getName(){
    return "roy";
}
Point Character:: getLocation(){
    return Point(0.0,0.0);
}


string Character:: print(){
    return "roy asraf";
}

bool Character:: hasboolets(){
    return true;
}