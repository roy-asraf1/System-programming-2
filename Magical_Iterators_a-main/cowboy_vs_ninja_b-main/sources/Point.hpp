
#include <iostream>

using namespace std;
namespace ariel
{
    class Point
    {
    protected:
        double my_x, my_y;

    public:
        
        Point(double point_x = 0, double point_y = 0);
         Point(Point const &point);
        double distance(Point other);
        double getX() const;
        double getY() const;
        void setX(double my_x);
        void setY(double my_y);
        void print();

        static Point moveTowards(Point source, Point dest, double dis);
        

    };

}
