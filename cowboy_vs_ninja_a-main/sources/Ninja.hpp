#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;
    public:
        Ninja(const std::string& name, const Point& location, int hitp, int speed);
        Ninja(string name, Point point);
        int getSpeed();
        void move(Character* enemy);
        void slash(Character* enemy);
    };
}

