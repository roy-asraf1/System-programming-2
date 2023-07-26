#include "Team2.hpp"
using namespace std;

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}

    Team2::~Team2()
    {
    }

    void Team2::attack(Team *opponent)
    {
        if (opponent == nullptr)
        {
            throw std::invalid_argument("null pointer");
        }
        if (opponent->stillAlive() > 0)
        {
            for (auto &teamMember : _team)
            {
                if (teamMember->isAlive())
                {
                    if (opponent->stillAlive() > 0)
                    {
                        if(teamMember->getType() =="C"){
                            attaccowboy(teamMember, opponent);
                        }
                        else{
                            attackninja(teamMember, opponent);
                        }
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
        else
        {
            throw std::runtime_error("is a dead team");
        }
    }
}