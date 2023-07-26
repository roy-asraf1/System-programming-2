#include "Cowboy.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(110, name, location, "C"), numOfboolets(6)
{
}
Cowboy::Cowboy(const Character& character) :Character(110,character.getName(),Point(character.getX(),character.getY()),"C"),numOfboolets(6){

}

int Cowboy::getBullets()
{
    return this->numOfboolets;
}
void Cowboy::setBullets(int bulletsintheFuture)
{
    numOfboolets=bulletsintheFuture;
}
bool Cowboy::hasboolets()
{
  
    if (getBullets()>0)
    {
        return true;
    }
        return false;
             
    
}
void Cowboy::reload()
{
    if (!isAlive())
    {
        throw std::runtime_error ("cant reload");
    }
        numOfboolets=6; //reload

    
}
void Cowboy::shoot(Character *enemy)
{
    if (this == enemy) {
        throw std::runtime_error("Can't shoot yourself");
    }
    if (!isAlive()) {
        throw std::runtime_error("Can't shoot, I'm dead");
    }
    if (!enemy->isAlive()) {
        throw std::runtime_error("The enemy is already dead");
    }
    if (hasboolets()) {
         enemy->sethitPoints(enemy->gethitPoints() - 10);
    numOfboolets = getBullets() - 1;
    }
  
}
// void Cowboy::shoot(Character *enemy)
// {
//     if (this == enemy)
//         throw std::runtime_error ("cant shoot");
//     if (isAlive() )
//     {   
//         if (hasboolets()){
//             enemy->sethitPoints(enemy->gethitPoints() - 10);
//             numOfboolets=getBullets()-1;
//         }

//     }else{
//         throw std::runtime_error ("cant shoot, i dead");
//     }
// }
