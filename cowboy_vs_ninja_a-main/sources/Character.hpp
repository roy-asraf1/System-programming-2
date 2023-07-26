#pragma once
#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel
{

    class Character : public Point
    {
    private:
        Point loc;
        int hitPoints;
        std::string name;

    public:
        
        Character(std::string name, const Point& point, int hitPoints);
        Character& operator=(const Character& other);
        bool isAlive();
        double distance(Character *);
        void hit(int);
        string getName();
        Point getLocation();

        string print();

        bool hasboolets();
    };

}
