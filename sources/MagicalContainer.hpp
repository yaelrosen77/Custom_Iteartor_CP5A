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

    public: 
        MagicalContainer(){}
        MagicalContainer(MagicalContainer&& other) = default;
        MagicalContainer(MagicalContainer& other);
        void addElement(int a){return;}
        void removeElement(int b){return;}
        int size(){return contsize;}
        void operator=(MagicalContainer&& other);
        MagicalContainer& operator=(const MagicalContainer &other){return *this;}

        class AscendingIterator{
            MagicalContainer& conti;
            int idx;
            public:
                AscendingIterator(MagicalContainer& cont) : conti(cont),idx(0){}
                AscendingIterator(const AscendingIterator &other):conti(other.conti),idx(other.idx){}
                AscendingIterator(AscendingIterator&& other) = default;
                AscendingIterator& operator=(AscendingIterator&& other) = delete;
                ~AscendingIterator() = default;
                bool operator ==(const AscendingIterator other){return false;}
                bool operator != (const AscendingIterator other){return false;}
                bool operator >(const AscendingIterator other){return false;}
                bool operator <(const AscendingIterator other){return false;}
                int& operator*() const {return conti.contsize;}
                AscendingIterator& operator++(){idx++;
                return *this;}
                AscendingIterator begin(){return AscendingIterator(conti);}
                AscendingIterator end(){AscendingIterator itr = *this;
                return itr;}
        };
        class SideCrossIterator{
            MagicalContainer* conti;
            public:
            SideCrossIterator(MagicalContainer& cont){}
            SideCrossIterator(const SideCrossIterator &other){}
            SideCrossIterator(SideCrossIterator&& other) = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
            ~SideCrossIterator() = default;
            bool operator ==(const SideCrossIterator other){return false;}
            bool operator != (const SideCrossIterator other){return false;}
            bool operator >(const SideCrossIterator other){return false;}
            bool operator <(const SideCrossIterator other){return false;}
            int& operator*() const {return conti->contsize;}
            SideCrossIterator& operator++(){return *this;}
            SideCrossIterator begin(){return *this;}
            SideCrossIterator end(){return *this;}
        };

        class PrimeIterator{
            MagicalContainer* conti;
            
            public:
                PrimeIterator(MagicalContainer& cont){}
                PrimeIterator(const PrimeIterator &other){}
                PrimeIterator(PrimeIterator&& other) = default;
                PrimeIterator& operator=(PrimeIterator&& other) = delete;
                ~PrimeIterator() = default;
                bool operator ==(const PrimeIterator other){return false;}
                bool operator != (const PrimeIterator other){return false;}
                bool operator >(const PrimeIterator other){return false;}
                bool operator <(const PrimeIterator other){return false;}
                int& operator*() const {return conti->contsize;}
                PrimeIterator& operator++(){return *this;}
                PrimeIterator begin(){return *this;}
                PrimeIterator end(){return *this;}
        };

};

}
