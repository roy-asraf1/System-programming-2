#pragma one

#include <vector>
#include<iostream>
#include <functional>
#include <algorithm>
#include <stdexcept>

using namespace std;
namespace ariel{



class MagicalContainer {
private:
    vector<int> numbers;
public:
    
    bool isPrime(int); 
    void addElement(int);
    void removeElement(int);
    vector<int> getElement();
    int size();
    

    class AscendingIterator {
    private:
        MagicalContainer* container;
        int index;

    public:
        AscendingIterator(MagicalContainer* , int);
        AscendingIterator(MagicalContainer&);

        AscendingIterator begin();
        AscendingIterator end();

        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& ) const;
        bool operator!=(const AscendingIterator& ) const;
        bool operator>(const AscendingIterator& ) const;
        bool operator<(const AscendingIterator& ) const;
        AscendingIterator& operator<<(int );
        AscendingIterator& operator>>(int );
        int operator*() const;
        void sortAscendingIterator(MagicalContainer*);
    };

    class SideCrossIterator {
    private:
        MagicalContainer* container;
        int index;
        int direct; 

    public:

        SideCrossIterator();
        SideCrossIterator(MagicalContainer* , int , int );
        SideCrossIterator(MagicalContainer& );

        SideCrossIterator begin();
        SideCrossIterator end();

        SideCrossIterator& operator++();
        bool operator==(const SideCrossIterator& ) const;
        bool operator!=(const SideCrossIterator& ) const;
        bool operator>(const SideCrossIterator& ) const;
        bool operator<(const SideCrossIterator& ) const;
        SideCrossIterator& operator<<(int );
        SideCrossIterator& operator>>(int );
        int operator*() const;
    };

    class PrimeIterator {
    private:
        MagicalContainer* container;
        int index;

    public:
        PrimeIterator();
        PrimeIterator(MagicalContainer* , int );
        PrimeIterator(MagicalContainer& );

        PrimeIterator begin();
        PrimeIterator end();

        PrimeIterator& operator++();
        bool operator==(const PrimeIterator&) const;
        bool operator!=(const PrimeIterator&) const;
        bool operator>(const PrimeIterator&) const;
        bool operator<(const PrimeIterator&) const;
        PrimeIterator& operator<<(int);
        PrimeIterator& operator>>(int);
        int operator*() const;
           

    };

};

}
