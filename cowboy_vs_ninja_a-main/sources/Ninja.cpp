#include "Ninja.hpp"
#include <cmath>

namespace ariel
{
    Ninja::Ninja(const std::string &name, const Point &location, int hitp, int speed) : Character(name, location, hitp), speed(speed)
    {
    }

    Ninja::Ninja(string name, Point point) : Character(name, point, 0), speed(0)
    {
    }

    int Ninja::getSpeed()
    {
        return this->speed;
    }

    void Ninja::move(Character *enemy)
    {
    }

    void Ninja::slash(Character *enemy)
    {

        if (isAlive())
        {
            double distance = this->getLocation().distance(enemy->getLocation());
            if (distance < 1.0)
            {
                enemy->hit(40);
            }
        }
    }

}
