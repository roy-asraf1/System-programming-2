#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include <vector>

using namespace std;
namespace ariel{
    

class SmartTeam: public Team  
{
private:


public:
    Character& operator=(const Character& other);
    SmartTeam(Character* );
    void add(Character*);
    void attack(SmartTeam*);
    int stillAlive();
    void print();
};
}
