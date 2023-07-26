#include "YoungNinja.hpp"
namespace ariel
{


YoungNinja::YoungNinja( std::string name,  Point point) : Ninja(14, name, 100, point)
{
}

YoungNinja::YoungNinja( Character character) : Ninja(14, character.getName(), 100,character.getLocation())
{
}

}