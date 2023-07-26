
#ifndef Cowboy_H
#define Cowboy_H
#include <iostream>
using namespace std;
#include "Character.hpp"
namespace ariel
{

    class Cowboy : public Character
    {
    protected:
        int numOfboolets;

    public:

        Cowboy(std::string name, Point location);
        Cowboy(const Character& character);
        virtual ~Cowboy()override {} ;
        bool hasboolets();
        void reload();
        void shoot(Character *);
        int getBullets();
        void setBullets(int);
        string  print() override
        {
            string output = "";
            if (hitPoints == 0)
            {
                output = "C" + name + ", "
                    + "(" + std::to_string(getX()) + "," + std::to_string(getY()) + ")\n";
            }
            else
            {
                output = "C" + name + ", " + std::to_string(hitPoints) + ", "
                        + "(" + std::to_string(getX()) + "," + std::to_string(getY()) + ")\n";
            }
            return output;
        }
    };
}

#endif