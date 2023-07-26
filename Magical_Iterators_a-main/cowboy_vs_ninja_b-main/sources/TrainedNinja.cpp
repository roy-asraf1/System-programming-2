#include "TrainedNinja.hpp"

using namespace ariel;


TrainedNinja::TrainedNinja(const std::string& name, const Point& point) : Ninja(12, name, 120, point)
{
}

TrainedNinja::TrainedNinja(const Character& character) : Ninja(12, character.getName(), 120,Point(character.getX(),character.getY()))
{
}


