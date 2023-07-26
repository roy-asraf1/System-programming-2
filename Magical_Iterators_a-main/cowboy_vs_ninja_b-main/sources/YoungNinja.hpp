
#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include "Ninja.hpp"
using namespace std;
namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja( string name, Point point);
        YoungNinja( Character );
        virtual ~YoungNinja()override{};
    };
}
#endif