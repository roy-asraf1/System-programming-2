#ifndef Team2_H
#define Team2_H

#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include "Team.hpp"

namespace ariel
{
    class Team2 : public virtual Team
    {
    private:
    public:
        Team2(Character *leader);
        ~Team2();

  
     void attack(Team* );
    
    };
}
#endif