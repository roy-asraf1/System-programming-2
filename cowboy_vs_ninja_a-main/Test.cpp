#include "doctest.h"

#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/SmartTeam.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"

using namespace ariel;

TEST_CASE("Point - calaculate the distance")
{
    Point p1(0, 0);
    Point p2(3, 4);
    double expected_dist = 5;
    CHECK_EQ(p1.distance(p2), expected_dist);
}

TEST_CASE("Character - check the isalive function")
{
    Point zero(0, 0);

    SUBCASE("HP > 0")
    {
        Character c("ROY", zero, 100);
        CHECK_EQ(c.isAlive(), true);
    }

    SUBCASE("HP < 0")
    {
        Character c("ROY", zero, -10);
        CHECK_EQ(c.isAlive(), false);
    }

    SUBCASE("HP == 0")
    {
        Character c("ROY", zero, 0);
        CHECK_EQ(c.isAlive(), false);
    }
}

TEST_CASE("Character - check the distance Calculation")
{
    Point p1(0, 0);
    Point p2(3, 4);
    Character c1("Player1", p1, 100);
    Character c2("Player2", p2, 100);
    CHECK_EQ(c1.distance(&c2), 5);
    CHECK_EQ(c2.distance(&c1), 5);
}

TEST_CASE("Character - Hit")
{
    Point p(0, 0);
    Character c("Player", p, 100);
    CHECK_NOTHROW(c.hit(10));
    CHECK_EQ(c.isAlive(), true);
    CHECK_THROWS(c.hit(-10));
    CHECK_EQ(c.isAlive(), true);
    CHECK_NOTHROW(c.hit(110));
    CHECK_EQ(c.isAlive(), false);
}

TEST_CASE("Character - Get Name")
{
    Point p(0, 0);
    Character c("Ninja", p, 100);
    CHECK_EQ(c.getName(), "Ninja");
}

TEST_CASE("Character - Get Location")
{
    Point p(1.2, 3.4);
    Character c("Ninja", p, 100);
    CHECK_EQ(c.getLocation().getX(), 1.2);
    CHECK_EQ(c.getLocation().getY(), 3.4);
}

TEST_CASE("Cowboy - Bullet Status")
{
    Cowboy c("Cowboy", Point(0, 0));
    Cowboy c2("Cowboy2", Point(0, 0));
    
    CHECK_EQ(c.hasboolets(), true);
    for (int i = 0; i < 6; i++)
    {
        c.shoot(&c2);
    }
    CHECK_EQ(c.hasboolets(), false);
    CHECK_THROWS(c.shoot(&c2));
    CHECK_NOTHROW(c.reload());
    CHECK_THROWS(c2.shoot(&c));
}
TEST_CASE("Ninja - Slash")
{
    Point p1(0, 0);
    Point p2(1, 1);
    Ninja ninja("Ninja1", p1);
    Cowboy cowboy("Cowboy1", p2);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    ninja.slash(&cowboy);
    CHECK_EQ(cowboy.isAlive(), false);
}

TEST_CASE("Team - Adding Characters")
{
    Cowboy cowboy("Cowboy1", Point(0, 0));
    Team team(&cowboy);

    Ninja ninja1("Ninja1", Point(2, 2), 120, 12);
    Ninja ninja2("Ninja2", Point(3, 3), 120, 12);
    team.add(&ninja1);
    team.add(&ninja2);

    CHECK_EQ(team.stillAlive(), 3);
}

TEST_CASE("Team - Maximum Characters")
{
    Cowboy c("Cowboy1", Point(0, 0));
    Team team(&c);

    for (int i = 0; i < 9; i++)
    {
        Ninja n("Ninja", Point(i, i), 120, 12);
        team.add(&n);
    }

    Ninja n2("Ninja2", Point(2, 7), 120, 12);
    CHECK_THROWS(team.add(&n2));
}



TEST_CASE("Cowboy Test - Default Constructor")
{
    Cowboy c("ROY", Point(1, 1));
    CHECK_EQ(c.getName(), "John");
    CHECK_EQ(c.hasboolets(), true);
}

TEST_CASE("Cowboy Test - Shoot Method")
{
    Cowboy c1("ROY", Point(1, 1));
    Cowboy c2("MOSHIKO", Point(2, 1));
    c1.shoot(&c2);
    CHECK_EQ(c2.isAlive(), false);
}

TEST_CASE("OldNinja Test - Slash Method")
{
    OldNinja n("Ninja", Point(2, 2));
    Cowboy c1("ROY", Point(1, 1));
    n.slash(&c1);
    CHECK_EQ(c1.isAlive(), false);
}

TEST_CASE("Point Test - Distance Calculation")
{
    Point p1(5.0, 10.0);
    Point p2(10.0, 10.0);
    CHECK_EQ(p1.distance(p2), 5.0);
}


TEST_CASE("Point Test - Distance Calculation")
{
    Point p1(5.0, 10.0);
    Point p2(10.0, 10.0);
    CHECK_EQ(p1.distance(p2), 5.0);
}

TEST_CASE("Cowboy Test - Reloading")
{
    Point p1(0, 0);
    Cowboy c1("Cowboy", p1);
    OldNinja ssusi("Ninja", p1);
    CHECK_EQ(c1.hasboolets(), true);
    for (int i = 0; i < 6; i++)
    {
        c1.shoot(&ssusi);
    }
    CHECK_EQ(c1.hasboolets(), false);
    c1.reload();
    CHECK_EQ(c1.hasboolets(), true);
}

TEST_CASE("Game Testing")
{
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy", p1);
    OldNinja ninja("Ninja", p2);
    Team teamA(&cowboy);
    Team teamB(&ninja);

        teamA.attack(&teamB);
        teamB.attack(&teamA);
    
    CHECK_NOTHROW(teamA.print());
    CHECK_NOTHROW(teamB.print());
}

