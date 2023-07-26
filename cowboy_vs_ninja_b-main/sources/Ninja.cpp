#include "Ninja.hpp"
#include <cmath>

namespace ariel
{
    Ninja::Ninja(int spe, string name, int hitp, Point point) : Character(hitp, name, point, "N"), speed(spe)
    {
    }

    // Ninja::Ninja(string name, Point point) : Character(name, point, 0), speed(0)
    // {
    // }
    int Ninja::getSpeed()
    {
        return this->speed;
    }

    void Ninja::move(Character *enemy)
    {
        int dist = speed;
        if (this->distance(enemy) < speed)
            setLocation(Point(enemy->getLocation().getX(), enemy->getLocation().getY()));
        else
            setLocation(this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), (double)speed));
    }

    void Ninja::slash(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("You can't attacking you");
        }
        if (isAlive())
        {
            if (this->distance(enemy) < 1)
                enemy->hit(40);
        }
        else
        {
            throw std::runtime_error("A dead player cannot attack");
        }
    }
}
