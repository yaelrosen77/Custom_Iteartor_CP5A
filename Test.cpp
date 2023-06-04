#include "doctest.h"
#include <stdexcept>
#include <cstdlib>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("A check that a new magical container is adequtely instantiated"){
    MagicalContainer tmp1{}; 
    CHECK_NOTHROW(MagicalContainer tmp());          //constructor should work with no parameters 
    CHECK_EQ(tmp1.size(),0);                        //a new container should have 0 elements
    CHECK_NOTHROW(MagicalContainer tmp = tmp1);     //checking the overloaded operator= 
    CHECK_NOTHROW(MagicalContainer tmp = move(tmp1));       //a move operator
    tmp1.addElement(4);                                 //check that after adding elements to the container it is properly assigned to the other container after moving it.
    tmp1.addElement(5);
    MagicalContainer tmp = move(tmp1);
    CHECK_EQ(tmp.size(),2);
}

TEST_CASE("Adding elements to the container and removing"){
    MagicalContainer tst2;
    CHECK_NOTHROW(tst2.addElement(1));          //adding elements doesnt throw unexpected errors
    tst2.addElement(1);
    CHECK_NOTHROW(tst2.removeElement(1));       //removing elements doesnt throw unexcpected errors
    tst2.addElement(2);                         
    tst2.addElement(3);
    tst2.addElement(4);
    tst2.addElement(5);
    tst2.addElement(6);
    CHECK_EQ(tst2.size(),6);                    //checking that the size of container is updated after various insertions
    tst2.removeElement(2);
    tst2.removeElement(3);
    tst2.removeElement(4);
    CHECK_EQ(tst2.size(),3);                    //checking that the size of container is updated after various deletions
    
    CHECK_NOTHROW(tst2.addElement(4));          //adding existing elemnts doesnot throw exceptions
    CHECK_NOTHROW(tst2.addElement(5));
    tst2.addElement(3);                         //adding the same elements wont throw exception but wont support duplications
    tst2.addElement(3);
    tst2.addElement(3);
    CHECK_EQ(tst2.size(),6);
    CHECK_THROWS(tst2.removeElement(8));        //throw error while removing uneexisting values in the container
    CHECK_THROWS(tst2.removeElement(9));
    for (int i=7; i<20; i++){
        CHECK_NOTHROW(tst2.addElement(i));      //the size of container should be dynamic and change its size even after 20 insertions
    }
}

TEST_CASE("Ascending iterator functionality"){
    MagicalContainer *tst3;
    CHECK_NOTHROW(MagicalContainer :: AscendingIterator(*tst3));
    MagicalContainer::AscendingIterator iter(*tst3);
    CHECK_NOTHROW(MagicalContainer :: AscendingIterator itie (*tst3));
    tst3->addElement(1);
    CHECK_NOTHROW(iter.begin());
    CHECK_NOTHROW(*iter);
    CHECK_EQ(iter.begin(),1);
    CHECK_NOTHROW(auto itie = iter);
    srand((unsigned) time(NULL));
    int random = rand() % 30;
    






}