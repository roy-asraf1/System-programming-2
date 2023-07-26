# include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;

Point::Point(Point const &point):my_x(point.getX()),my_y(point.getY()){

}

Point::Point(double point_x , double point_y ): my_x(point_x), my_y(point_y) 
{

}

double Point::distance(Point other)
{
    return sqrt(pow(my_x - other.my_x, 2) + pow(my_y - other.my_y, 2));
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

    
