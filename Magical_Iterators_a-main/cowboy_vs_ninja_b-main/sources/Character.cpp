#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Character::Character(int hitPoints, string name, Point point, string type)
    : hitPoints(hitPoints), name(name), point(point), type(type),part_of_the_group(false)
{
    
}

bool Character::isAlive()
{
    if (hitPoints != 0)
    {
        return true;
    }
    return false;
}

double Character::distance(Character *player)
{

    return point.distance(player->point);
}

int Character::gethitPoints()
{
    return hitPoints;
}

Point Character::getLocation()
{  
    return this->point;
}

void Character::sethitPoints(int newHitPoints)
{
    hitPoints = newHitPoints;
}

void Character::hit(int hitPointsToDecrease)
{
    if (hitPointsToDecrease < 0)
    {
        throw std::invalid_argument("A negative number of points cannot be deducted for a player");
    }
    if (hitPoints > 0)
    {
        if (hitPoints >= hitPointsToDecrease)
        {
            hitPoints -= hitPointsToDecrease;
        }
        else
        {
            hitPoints = 0;
        }
    }
    else
    {
        throw std::runtime_error("You are attacking a dead character");
    }
}
string Character:: getType (){
    return type;
}

std::string Character::getName() const
{
    return name;
}

// print for charcter for cowboy and ninja we need to do override
string Character::print()
{
    string output = "";
    if (hitPoints == 0)
    {
        output = type + ", " + name + ", " + "(" + std::to_string(getX()) + "," + std::to_string(getY()) + ")\n";
    }
    else
    {
        output = type + ", " + name + ", " + std::to_string(hitPoints) + ", " + "(" + std::to_string(getX()) + "," + std::to_string(getY()) + ")\n";
    }
    return output;
}

void Character::setLocation(Point newloc)
{
    point = Point(newloc.getX(), newloc.getY());
}

void Character::setPartOfgroup(bool boole){
    part_of_the_group = boole;
}
bool Character::getPartOfgroup(){
    return part_of_the_group;
}
