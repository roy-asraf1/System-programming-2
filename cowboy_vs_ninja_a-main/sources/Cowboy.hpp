
#pragma once
#include <iostream>
using namespace std;
#include "Character.hpp"
namespace ariel
{

    class Cowboy : public Character
    {
    private:
        int getBulletCount; 

    public:
        
        Cowboy(std::string name, Point location);
        bool hasboolets();
        void reload();
        void shoot(Character *);
    };
}