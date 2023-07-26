#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel
{
    class SmartTeam
    {
        private:
            Character *_leader;
            std::vector<Character *> _team;
            int sizeOfTeam;
        
        public:
            SmartTeam(Character * leader);
            ~SmartTeam(); // destructor

            void add(Character * member);
            void add(Ninja *ninja);
            void add(Cowboy *cowboy);

            void attack(SmartTeam * other);
            int instanceOff(Character *character);
            int stillAlive() const;
            int secondLeader(SmartTeam *otherTeam);
            void print();

    };
}