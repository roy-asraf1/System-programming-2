#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
#include <typeinfo>
#include <sstream>
#include <limits>
#include <vector>
#include <iostream>

using namespace ariel;
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
TEST_SUITE("MagicalContainer constructors tests and invalid constructors")
    {
    TEST_CASE("AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);

        // Obtain the iterators directly
        auto containerElements = container.getElement();
        auto beginIter = MagicalContainer::AscendingIterator(&container, 0);
        auto endIter = MagicalContainer::AscendingIterator(&container, container.size());

        // Test the iterator behavior
        CHECK(beginIter == endIter);
        CHECK_NOTHROW(++beginIter);
        CHECK(beginIter == endIter);
       
    }


    TEST_CASE("PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);

        // Obtain the iterators directly
        auto containerElements = container.getElement();
        auto beginIter = containerElements.begin();
        auto endIter = containerElements.end();

        // Test the iterator behavior
        CHECK(beginIter == endIter);
        CHECK_NOTHROW(++beginIter);
        CHECK(beginIter == endIter);
        
    }
    TEST_CASE("SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        auto containerElements = container.getElement();
        auto beginIter = containerElements.begin();
        auto endIter = containerElements.end();

        // Test the iterator behavior
        CHECK(beginIter == endIter);
        CHECK_NOTHROW(++beginIter);
        CHECK(beginIter == endIter);
        
    }

}

TEST_SUITE("function tests")
{
    TEST_CASE("addElement")
    {
        MagicalContainer container;

        CHECK_NOTHROW(container.addElement(5));
        CHECK_EQ(container.size(), 1);   // The container size should be 1
        CHECK_EQ(container.getElement()[0], 5); // The first element in the container should be 5

        container.addElement(3);
        container.addElement(7);
        CHECK_EQ(container.size(), 3);   // The container size should be 3 after adding more elements

        // Check that all the added elements are present in the container
        std::vector<int> expectedElements = {5, 3, 7};
        auto containerElements = container.getElement();
        for (size_t i = 0; i < expectedElements.size(); ++i)
        {
            CHECK_EQ(containerElements[i], expectedElements[i]);
        }
}


    TEST_CASE("size")
    {
        MagicalContainer container;

        container.addElement(5);
        container.addElement(3);

        CHECK_EQ(container.size(), 2); // The container size should be 2

        container.addElement(7);
        container.removeElement(5);
        CHECK_EQ(container.size(), 2); // The container size should still be 2 after removing an element
        container.removeElement(3);
        CHECK_EQ(container.size(), 1); // The container size should be 1 after removing another element
    }

    TEST_CASE("removeElement")
    {
        MagicalContainer container;

        container.addElement(5);
        container.addElement(3);

        container.removeElement(3);
        CHECK_EQ(container.size(), 1);// The container size should be 1 after removing an element

        container.removeElement(5);
        CHECK_EQ(container.size(), 0); // The container size should be 0 after removing the remaining element
       
    }

}

TEST_SUITE(" == operator tests")
{

    TEST_CASE("check ==")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);

        auto containerElements = container.getElement();

        // Create iterators based on indices
        auto iter1 = containerElements.begin();
        auto iter2 = containerElements.begin();

        CHECK((iter1 == iter2));
        CHECK_NOTHROW(iter1++);
        CHECK(iter1 == iter2); // The iterators should still be equal after incrementing one of them
    }


}
TEST_SUITE("!= operator tests")
{

    TEST_CASE("check!=")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);

        auto containerElements = container.getElement();
        auto iter1 = containerElements.begin();
        auto iter2 = containerElements.begin();

        CHECK((iter1 != iter2));
        CHECK_NOTHROW(iter1++);
        CHECK(iter1 != iter2); // The iterators should still not be equal after incrementing one of them
    }

}


TEST_SUITE("operator tests")
{
    TEST_CASE("check * operator")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();

        CHECK_EQ(*iter, 5);
        ++iter;
        CHECK_EQ(*iter, 3); // The dereferenced value of the iterator should be 3 after incrementing it
    }


}

TEST_SUITE(" < and > operators tests")
{
    TEST_CASE("check <>")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);

        auto containerElements = container.getElement();
        auto iter1 = containerElements.begin();
        auto iter2 = containerElements.end();

        CHECK((iter1 < iter2));
        CHECK((iter2 > iter1));
        ++iter1;
        CHECK(iter1 < iter2); // The first iterator should still be less than the second iterator after incrementing it
        CHECK(iter2 > iter1); // The second iterator should still be greater than the first iterator after incrementing it
    }
}
TEST_SUITE("++ and check ++ test is working also the ++ not more than the max int")
{
    TEST_CASE("check ++")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();

        // Check pre-increment operator
        auto iter1 = ++iter;
        CHECK_EQ(*iter1, 2);

        // Check post-increment operator
        auto iter2 = iter++;
        CHECK_EQ(*iter2, 2);
        CHECK_EQ(*iter, 3);
    }
}

TEST_SUITE(" << operator tests")
{
    TEST_CASE("check <<")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();

        std::stringstream ss;
        ss << *iter;

        CHECK_EQ(ss.str(), "5");
    }
}

TEST_SUITE(" >> operator tests")
{
    TEST_CASE("check >>")
    {
        MagicalContainer container;
        int value = 0;
        std::stringstream ss("5");
        ss >> value;

        container.addElement(value);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();
        CHECK_EQ(*iter, 5);
    }
}
TEST_SUITE("begin tests")
{
    TEST_CASE("begin")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();
        CHECK_EQ(*iter, 5);
    }
}

TEST_SUITE("Prime function")
{
    TEST_CASE("Prime")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();

        // Find the first prime number
        while (!isPrime(*iter))
        {
            ++iter;
        }

        CHECK_EQ(*iter, 2);
    }

    TEST_CASE("PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();

        // Find the first prime number
        while (!isPrime(*iter))
        {
            ++iter;
        }

        CHECK_EQ(*iter, 2);
    }

    TEST_CASE("SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);

        auto containerElements = container.getElement();
        auto iter = containerElements.begin();

        // Find the first prime number
        while (!isPrime(*iter))
        {
            ++iter;
        }

        CHECK_EQ(*iter, 2);
    }
}

