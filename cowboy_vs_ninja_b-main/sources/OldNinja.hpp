#ifndef OldNinja_H
#define OldNinja_H
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        
        OldNinja(const std::string& name, const Point& point);
        OldNinja(const Character& character);
        virtual ~OldNinja()override{};
    };
}
#endif