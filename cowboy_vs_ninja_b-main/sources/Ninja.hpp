#ifndef Ninja_H
#define Ninja_H
#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
    protected:
        int speed;

    public:
        Ninja(int, string, int, Point);
       // Ninja(string name, Point point);
        virtual ~Ninja()override{}; 
        int getSpeed();
        void move(Character *);
        void slash(Character *);
       
       


    };
}
#endif