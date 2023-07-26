#ifndef Team_H
#define Team_H

#include <iostream>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cfloat>

namespace ariel
{
    class Team
    {
    protected:
        Character *captain;
        std::vector<Character *> _team;
        int sizeOfTeam;
        int count;

    public:
        Team(Character *leader);
        ~Team(); // destructor
        int instanceOff(Character *character);
        void setCaptain(Character *chara);
        void add(Character *member);
        ;
        Character *getLeader();
        Character *findClosestToCaptain(Character *captain, vector<Character *> team2);
        virtual void attack(Team* );
        void attackninja(Character *player,Team*);
        void attaccowboy(Character *player,Team*);
        int stillAlive();
        virtual int secondLeader(Team *otherTeam);
        virtual void print();
        const std::vector<Character *> &getTeamMembers() const;
    };
}
#endif