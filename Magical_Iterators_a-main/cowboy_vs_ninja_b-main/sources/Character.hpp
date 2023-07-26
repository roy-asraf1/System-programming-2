#ifndef Character_H
#define Character_H
#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace ariel
{
    class Character : public Point
    {
    protected:
        int hitPoints;
        string name,type;
        Point point;
        bool part_of_the_group;
    public:
      
        virtual ~Character() {} // Add a virtual destructor
        //Character(string name, Point point, int hitPoints);

        Character(int hitPoints, string name,  Point point, string type);
        // Character &operator=(const Character &other);
        bool isAlive();
        double distance( Character*);
        void hit(int);
        string getName() const;

        int gethitPoints()  ;
        void sethitPoints(int);
        Point getLocation();
        virtual string print() ;
        void setLocation(Point );
        void setPartOfgroup(bool);
        bool getPartOfgroup();
        string getType ();
    };

}
#endif