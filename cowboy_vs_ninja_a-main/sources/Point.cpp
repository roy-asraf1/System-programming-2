# include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace std;
using namespace ariel;



double Point::distance(Point other)
{
    return sqrt(pow(this->my_x - other.my_x, 2) + pow(this->my_y - other.my_y, 2));
}

double Point::getX() const
{
    return this->my_x;
}

double Point::getY() const
{
    return this->my_y;
}

void Point::setX(double x)
{
    this->my_x = x;
}

void Point::setY(double y)
{
    this->my_y = y;
}

Point Point::moveTowards(Point source, Point dest, double dis)
    {
        if(dis < 0) throw invalid_argument("Distance can't be negative!");

        double disX = dest.my_x - source.my_x;
        double disY = dest.my_y - source.my_y;
        double curDist = source.distance(dest);
        if( curDist <= dis ) return dest;
        else
        {
            double flag = dis / curDist;
            double newX = source.my_x + (disX * flag);
            double newY = source.my_y + (disY * flag);
            return Point(newX, newY);
        }
    }

void Point::print(){
    cout <<"(" << getX()<<","<<getY()<<")"<<endl;
}

    
