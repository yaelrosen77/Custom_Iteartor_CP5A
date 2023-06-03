#pragma once
#include <iostream>
#include <forward_list>                     //best for keeping track only of the next element
using namespace std;
// #include <MysticalElements.hpp>
// using namespace ariel;

namespace ariel{

class MagicalContainer{
    forward_list<int> iteratia;
    // MysticalPrimeElement* firstp;                   //the first prime element to be stored
    int contsize;
        MagicalContainer(MagicalContainer&& other) = delete;
        MagicalContainer(MagicalContainer& other);
        MagicalContainer& operator=(MagicalContainer&& other) = delete;
        MagicalContainer& operator=(const MagicalContainer &other) = default;
                
    public: 
        MagicalContainer(){}
        void addElement(int a){return;}
        void removeElement(int b){return;}
        int size(){return contsize;}

        class AscendingIterator{
            forward_list<int> tmp;
            int* a;
            public:
                AscendingIterator(MagicalContainer& cont){}
                AscendingIterator(const AscendingIterator &other){}
                AscendingIterator(AscendingIterator&& other) = default;
                AscendingIterator& operator=(AscendingIterator&& other) = delete;
                ~AscendingIterator() = default;
                bool operator ==(const AscendingIterator other){return true;}
                bool operator != (const AscendingIterator other){return true;}
                bool operator >(const AscendingIterator other){return true;}
                bool operator <(const AscendingIterator other){return true;}
                int& operator*() const {return *a;}
                AscendingIterator& operator++(){return *this;}
                AscendingIterator begin(){return *this;}
                AscendingIterator end(){return *this;}
        };

        class SideCrossIterator{
            forward_list<int> tmp;
            int *b;
            public:
            SideCrossIterator(MagicalContainer& cont){}
            SideCrossIterator(const SideCrossIterator &other){}
            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
            ~SideCrossIterator() = default;
            bool operator ==(const SideCrossIterator other){return true;}
            bool operator != (const SideCrossIterator other){return true;}
            bool operator >(const SideCrossIterator other){return true;}
            bool operator <(const SideCrossIterator other){return true;}
            int& operator*() const {return *b;}
            SideCrossIterator& operator++(){return *this;}
            SideCrossIterator begin(){return *this;}
            SideCrossIterator end(){return *this;}
        };

        class PrimeIterator{
            forward_list<int> tmp;
            int *c;
            
            public:
                PrimeIterator(PrimeIterator& cont){}
                PrimeIterator(const PrimeIterator &other){}
                PrimeIterator(PrimeIterator&& other) = default;
                PrimeIterator& operator=(PrimeIterator&& other) = delete;
                ~PrimeIterator() = default;
                bool operator ==(const PrimeIterator other){return true;}
                bool operator != (const PrimeIterator other){return true;}
                bool operator >(const PrimeIterator other){return true;}
                bool operator <(const PrimeIterator other){return true;}
                int& operator*() const {return *c;}
                PrimeIterator& operator++(){return *this;}
                PrimeIterator begin(){return *this;}
                PrimeIterator end(){return *this;}
        };

};

}
