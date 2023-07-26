#include "SmartTeam.hpp"
#include <stdexcept>
#include <algorithm>
#include <limits>
using namespace std;

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : _leader(leader), sizeOfTeam(1)
    {
        _team.push_back(leader);
    }

    SmartTeam::~SmartTeam()
    {
        return;
    }
    void SmartTeam::add(Character *member)
    {
        if (sizeOfTeam == 10)
            throw runtime_error("The team is full!");
        _team.push_back(member);
        sizeOfTeam++;
    }
    void SmartTeam::add(Ninja *ninja)
    {
        if (sizeOfTeam == 10)
            throw runtime_error("The team is full!");
        _team.push_back(ninja);
        sizeOfTeam++;
    }

    void SmartTeam::add(Cowboy *cowboy)
    {
        if (sizeOfTeam == 10)
            throw runtime_error("The team is full!");
        _team.push_back(cowboy);
        sizeOfTeam++;
    }

    int SmartTeam::secondLeader(SmartTeam *otherTeam)
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

    int SmartTeam::instanceOff(Character *character)
    {
        if (dynamic_cast<Cowboy *>(character) != nullptr)
        {
            return 1; // Cowboy type
        }
        else if (dynamic_cast<Ninja *>(character) != nullptr)
        {
            return 2; // Ninja type
        }
        else
        {
            return 0; // Default case if the character doesn't match any of the specified types
        }
    }

    void SmartTeam::attack(SmartTeam *otherTeam)
    {
        if (otherTeam->_leader->isAlive())
        {
            // Calculate distances between characters in the attacking team and the opposing team
            std::vector<std::pair<double, Character *>> distances;
            for (Character *attacker : _team)
            {
                for (Character *defender : otherTeam->_team)
                {
                    double distance = attacker->distance(defender);
                    distances.emplace_back(distance, attacker);
                }
            }

            // Sort the attacking team's characters based on distance to the opposing team's characters
            std::sort(distances.begin(), distances.end());

            // Perform the attack based on the sorted distances
            for (const auto &pair : distances)
            {
                Character *attacker = pair.second;
                int type = instanceOff(attacker);

                if (attacker->isAlive() && type == 1) // Cowboy
                {
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(attacker);
                    if (cowboy->getBullets() == 0)
                    {
                        cowboy->reload();
                    }
                    else
                    {
                        Character *target = nullptr;
                        double minDistance = std::numeric_limits<double>::max();

                        // Find the closest alive character from the opposing team as the target
                        for (Character *defender : otherTeam->_team)
                        {
                            if (defender->isAlive() && attacker->distance(defender) < minDistance)
                            {
                                target = defender;
                                minDistance = attacker->distance(defender);
                            }
                        }

                        if (target)
                        {
                            cowboy->shoot(target);
                        }
                    }
                }
                else if (attacker->isAlive() && type == 2) // Ninja
                {
                    Ninja *ninja = dynamic_cast<Ninja *>(attacker);
                    Character *target = nullptr;
                    double minDistance = std::numeric_limits<double>::max();

                    // Find the closest alive character from the opposing team within a distance of 1 as the target
                    for (Character *defender : otherTeam->_team)
                    {
                        if (defender->isAlive() && attacker->distance(defender) <= 1 && attacker->distance(defender) < minDistance)
                        {
                            target = defender;
                            minDistance = attacker->distance(defender);
                        }
                    }

                    if (target)
                    {
                        ninja->slash(target);
                    }
                    else
                    {
                        // Find the closest alive character from the opposing team as the target
                        for (Character *defender : otherTeam->_team)
                        {
                            if (defender->isAlive() && attacker->distance(defender) < minDistance)
                            {
                                target = defender;
                                minDistance = attacker->distance(defender);
                            }
                        }
                        if (target)
                        {
                            ninja->move(target);
                        }
                    }
                }
            }
        }
        else
        {
            int index = secondLeader(otherTeam);
            if (index != -1)
            {
                for (Character *character : _team)
                {
                    int typeC = instanceOff(character);
                    if (character->isAlive() && typeC == 1)
                    {
                        Cowboy *tempcowboy = dynamic_cast<Cowboy *>(character);
                        if (tempcowboy->getBullets() == 0)
                        {
                            tempcowboy->reload();
                        }
                        else
                        {
                            tempcowboy->shoot(otherTeam->_team[static_cast<std::vector<Character *>::size_type>(index)]);
                        }
                    }
                }
                for (Character *character : _team)
                {
                    int typeN = instanceOff(character);
                    if (character->isAlive() && typeN == 2)
                    {
                        Ninja *tempNinja = dynamic_cast<Ninja *>(character);
                        if (tempNinja->distance(otherTeam->_team[static_cast<std::vector<Character *>::size_type>(index)]) <= 1)
                        {
                            tempNinja->slash(otherTeam->_team[static_cast<std::vector<Character *>::size_type>(index)]);
                        }
                        else
                        {
                            tempNinja->move(otherTeam->_team[static_cast<std::vector<Character *>::size_type>(index)]);
                        }
                    }
                }
            }
        }
    }

    int SmartTeam::stillAlive() const
    {
        int countOfAlives = 0;
        for (unsigned long int i = 0; i < sizeOfTeam; i++)
        {
            if (_team[i]->isAlive())
                countOfAlives++;
        }
        return countOfAlives;
    }

    void SmartTeam::print()
    {
        int typeC;
        int typeN;
        for (Character *character : _team)
        {
            typeC = instanceOff(character);
            if (typeC == 1)
            {
                Cowboy *temp = dynamic_cast<Cowboy *>(character);
                temp->print();
            }
        }
        for (Character *character : _team)
        {
            typeN = instanceOff(character);
            if (typeN == 2)
            {
                Ninja *temp = dynamic_cast<Ninja *>(character);
                temp->print();
            }
        }
    }
}
