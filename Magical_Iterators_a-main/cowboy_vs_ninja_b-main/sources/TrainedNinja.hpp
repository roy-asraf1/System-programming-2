 #ifndef TrainedNinja_H
 #define TrainedNinja_H

#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(const std::string& name, const Point& point);
        TrainedNinja(const Character& character);
        virtual ~TrainedNinja()override{};


    };
}
#endif