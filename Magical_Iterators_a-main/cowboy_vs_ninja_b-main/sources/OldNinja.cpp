#include "OldNinja.hpp"
#include "Character.hpp"

namespace ariel {

    OldNinja::OldNinja(const std::string& name, const Point& point) : Ninja(8, name, 150, point)
    {
    }

    OldNinja::OldNinja(const Character& character) : Ninja(8, character.getName(), 150, Point(character.getX(),character.getY()))
    {
    }

}
