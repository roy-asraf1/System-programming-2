#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;



bool MagicalContainer::isPrime(int n) {
    if (n <= 1)
        return false;
    
    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

vector<int> MagicalContainer::getElement(){
    return numbers;
}

void MagicalContainer::addElement(int elem) {
    numbers.emplace_back(elem);
}

void MagicalContainer::removeElement(int elem) {
    auto it = std::find(numbers.begin(), numbers.end(), elem);
    if (it != numbers.end()) {
        numbers.erase(it);
    }

    cout << "removeing..." << endl;
    for (auto it : numbers) {
        cout << it << ", ";
    }
    cout << endl;
    cout << "end removeing..." << endl;
    cout << endl;

    if (!numbers.empty()) {
        int num = numbers.back();
        cout << "end = " << num << endl;
    }
}




int MagicalContainer::size() {
    return numbers.size();
}

void MagicalContainer::AscendingIterator::sortAscendingIterator(MagicalContainer* container){
    std::sort( container->numbers.begin(), container->numbers.end());
    
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return AscendingIterator(container, container->size());
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer* container, int index)
    : container(container), index(index) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : container(&container), index(0)
{
sortAscendingIterator(&container);
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container):
container(&container), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container):
container(&container), index(0) {}




MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return other.index == index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return other.index != index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return index < other.index;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator<<(int steps) {
    index = index - steps;
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator>>(int steps) {
    index = index + steps;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const {
    unsigned long val=  static_cast<unsigned long>(index);
    return container->numbers[val];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(container, 0, 1);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return SideCrossIterator(container, container->size(), 1);
}

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), index(0), direct(1) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer* container, int index, int direct)
    : container(container), index(index), direct(direct) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    index += direct;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return other.index == index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return other.index != index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return index > other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return index < other.index;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator<<(int steps) {
    index -= steps * direct;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator>>(int steps) {
    index += steps * direct;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    unsigned long val=  static_cast<unsigned long>(index);
    return container->numbers[val];
}

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer* container, int index)
    : container(container), index(index) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++index;
    while (index < container->size()) {
        unsigned long jhg = static_cast<unsigned long>(index);
        if (container->isPrime(container->numbers[jhg])) {
            break;
        }
        ++index;
    }
    return *this;
}


bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return other.index != index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return other.index > index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return index < other.index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator<<(int steps) {
    int i = 0;
    for (;i < steps && index >= 0; --index) {
        unsigned long val = static_cast<unsigned long>(index);
        if (container->isPrime(container->numbers[val])) {
            ++i;
        }
    }
    return *this;
}


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator>>(int steps) {
    int i = 0;
    unsigned long jhg;
    for (; i < steps; ++index) {
        jhg = static_cast<unsigned long>(index);
        if (container->isPrime(container->numbers[jhg])) {
            ++i;
        }
    }
    return *this;

}

int MagicalContainer::PrimeIterator::operator*() const {
    unsigned long val=  static_cast<unsigned long>(index);
    return container->numbers[val];
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator(container, container->size());
}