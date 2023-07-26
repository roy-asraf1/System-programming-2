#include "Team.hpp"
using namespace std;

namespace ariel
{

    Team::Team(Character *leader) : captain(leader)
    {
        count = 0;
        if (captain->isAlive())
            add(captain);
    }

    Team::~Team()
    {
    }

    Character *Team::getLeader()
    {
        return captain;
    }

    void Team::add(Character *character)
    {
        if (character == nullptr)
        {
            throw std::runtime_error("Character cant be null");
        }
        if (std::find(_team.begin(), _team.end(), character) != _team.end())
        {
            throw std::runtime_error("Character on team");
        }
        if (_team.size() >= 10 || character->getPartOfgroup())
        {
            throw runtime_error("max 10 teammates");
        }
        _team.push_back(character);
        character->setPartOfgroup(true);
        ++count;
    }

    int Team::secondLeader(Team *otherTeam)
    {
        int maxHitpoints = 0;
        int secondLeaderIndex = -1;

        for (int i = 0; i < otherTeam->_team.size(); i++)
        {
            Character *character = otherTeam->_team[static_cast<std::vector<Character *>::size_type>(i)];
            if (character->isAlive() && character->gethitPoints() > maxHitpoints)
            {
                maxHitpoints = character->gethitPoints();
                secondLeaderIndex = i;
            }
        }

        return secondLeaderIndex;
    }

Character* Team::findClosestToCaptain(Character *captain, vector<Character *> team)
{
    double minimiumval = DBL_MAX;
    Character *closestCharacter = nullptr;

    auto it = team.begin();
    while (it != team.end())
    {
        if ((*it) != nullptr && (*it)->isAlive())
        {
            double distance = captain->distance(*it);
            if (distance <= minimiumval)
            {
                minimiumval = distance;
                closestCharacter = *it;
            }
        }
        ++it;
    }

    return closestCharacter;
}


    void Team::setCaptain(Character *chara)
    {
        if (chara->isAlive() && chara != nullptr)
        {
            captain = chara;
        }
    }
    const std::vector<Character *> &Team::getTeamMembers() const
    {
        return _team;
    }

    void Team::attackninja(Character *player, Team *team)
    {
        if (team->stillAlive() > 0)
        {
            Character *victim = findClosestToCaptain(captain, team->getTeamMembers());
            if (!captain->isAlive())
            {

                setCaptain(findClosestToCaptain(captain, getTeamMembers()));
            }

            if (YoungNinja *youngNinja = dynamic_cast<YoungNinja *>(player))
            {
                if (youngNinja->distance(victim) < 1)
                {
                    youngNinja->slash(victim);
                }
                else
                {
                    youngNinja->move(victim);
                }
            }
            else if (TrainedNinja *trainedNinja = dynamic_cast<TrainedNinja *>(player))
            {
                if (trainedNinja->distance(victim) < 1)
                {
                    trainedNinja->slash(victim);
                }
                else
                {
                    trainedNinja->move(victim);
                }
            }
            else if (OldNinja *oldNinja = dynamic_cast<OldNinja *>(player))
            {
                if (oldNinja->distance(victim) < 1)
                {
                    oldNinja->slash(victim);
                }
                else
                {
                    oldNinja->move(victim);
                }
            }
        }
    }
    void Team::attaccowboy(Character *player, Team *team)
    {
        if (team->stillAlive() > 0)
        {
            Character *victim = findClosestToCaptain(captain, team->getTeamMembers());
            if (!captain->isAlive())
            {

                setCaptain(findClosestToCaptain(captain, getTeamMembers()));
            }
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(player))
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(victim);
                }
                else
                {
                    cowboy->reload();
                }
            }
        }
    }

        void Team::attack(Team * opponent)
        {
            if (opponent == nullptr)
            {
                throw std::invalid_argument("Invalid pointer");
            }
            if (opponent->stillAlive() > 0)
            {
                // Cowboys
                for (auto &teamMember : _team)
                {
                    if (teamMember->gethitPoints() > 0)
                    {
                        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(teamMember))
                        {
                            if (opponent->stillAlive() > 0)
                            {
                                attaccowboy(cowboy, opponent);
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                }

                // Ninjas
                for (auto &teamMember : _team)
                {
                    if (teamMember->gethitPoints() > 0)
                    {
                        if (Ninja *ninja = dynamic_cast<Ninja *>(teamMember))
                        {

                            if (opponent->stillAlive() > 0)
                            {
                                attackninja(ninja, opponent);
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                }
            }
            else
            {
                throw std::runtime_error("Dead team");
            }
        }

        int Team::stillAlive()
        {
            int count = 0;
            for (Character *member : _team)
            {
                if (member->isAlive())
                {
                    count++;
                }
            }
            return count;
        }

        void Team::print()
        {
            for (Character *character : _team)
            {
                if (dynamic_cast<Cowboy *>(character) != nullptr)
                {
                    dynamic_cast<Cowboy *>(character)->print();
                }
            }
            for (Character *character : _team)
            {
                if (dynamic_cast<Ninja *>(character) != nullptr)
                {
                    dynamic_cast<Ninja *>(character)->print();
                }
            }
        }
    }
