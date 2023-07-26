#include "Cowboy.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), getBulletCount(6)
{}


bool Cowboy:: hasboolets(){
    return true;
}
void Cowboy:: reload(){

}
void Cowboy:: shoot(Character*){
    
}