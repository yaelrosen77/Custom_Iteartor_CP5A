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
    CHECK_EQ(tmp.size(),2);                         //should have the exact same elements we added earlier
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
    CHECK_NOTHROW(MagicalContainer :: AscendingIterator(*tst3));        //make sure its properly receive container
    MagicalContainer::AscendingIterator iter(*tst3);                    
    CHECK_NOTHROW(MagicalContainer :: AscendingIterator itie (*tst3));  //check that more than one iterator can be formed on the same container
    tst3->addElement(1);                                               
    CHECK_NOTHROW(iter.begin());                                        //no seg fault should be thrown by either begin or end function
    CHECK_NOTHROW(iter.end()); 
    CHECK_NOTHROW(*iter);                                               //not throwing error while dereferencing an operator
    CHECK_EQ(iter.begin(),1);                               //checking the value is properly extracted
    CHECK_NOTHROW(auto itie = iter);                    //no exception while assigning other iterator                         
    int random;
    srand((unsigned) time(NULL));
    CHECK_NOTHROW(++iter);
    for (int i=0; i<20; i++){                           //adding 30 random numbers to the container
        random = rand() % 30;
        tst3->addElement(random);                       
    } 
    int tmp = -1;
    for (auto itie = iter; itie<iter.end(); ++itie){        //checking that the order is indeed ascending
        CHECK_GT(*itie,tmp);
        tmp = *itie;
    }
    MagicalContainer conti;
    MagicalContainer:: AscendingIterator itie(conti);
    conti.addElement(7);
    conti.addElement(3);
    conti.addElement(9);
    conti.addElement(5);
    auto itt = itie;
    CHECK_NOTHROW(itt!=itie.end());
    while (itt!=itie.end()){                
        if (*itt == 5){                 //trying to add a smaller number while the iterator is in 5
            tst3->addElement(4);
            CHECK_NE(*itt,4);           //cheking that it is still pointing to 5 after the adding
        }
        if (*itt==7){
            tst3->addElement(8);        //adding one value after the curr one
            ++itt;
            CHECK_EQ(*itt,8);            //checking that in the next iteration the following element will be the one we just added
        }
        ++itt;
    }
    MagicalContainer::AscendingIterator ppt = itie.begin();  
    //here we check that even after adding and removing elements, the ascending order is preserved
    //this is done in a random way !! not every element in the container will be checked
    while(ppt<itie.end()){                      
        CHECK_LT(*ppt,*(++ppt));            //every previous value should be smaller than the next one
        random = rand() % 30;
        tst3->addElement(random);
        random = rand() % 30;
        tst3->removeElement(random);        //may remove an element or may not if it is the container
        random = rand() % 30;
        tst3->removeElement(random);
        random = rand() % 30;
        tst3->removeElement(random);
        ++ppt;
        ++ppt;
    }
    
    MagicalContainer::AscendingIterator ddt = itie.begin();
    MagicalContainer::AscendingIterator bbt = itie.begin();
    ++bbt;
    ++bbt;
    CHECK_NOTHROW(ddt>bbt);                 //checking operators safety
    CHECK_NOTHROW(ddt<bbt);                 
    CHECK_FALSE(ddt>bbt);                   //its an ascending order so no value should be bigger comparing to an incresed operator
    ++ddt;
    CHECK(ddt<bbt);
    CHECK_NOTHROW(ddt==bbt);                //saftey use of operators
    ++ddt;
    CHECK(ddt==bbt);                        //should point to the same element
}


TEST_CASE("Cross iterator functionality"){
    MagicalContainer tst4;
    CHECK_NOTHROW((MagicalContainer::SideCrossIterator(tst4)));      //make sure its properly receive container
    MagicalContainer::SideCrossIterator tmpi(tst4);
    CHECK_NOTHROW((MagicalContainer::SideCrossIterator(tst4)));      //a check that more than one iterator can work above the same container
    tst4.addElement(3);
    CHECK_NOTHROW(tmpi.begin());
    CHECK_NOTHROW(tmpi.end());
    CHECK_NOTHROW(*tmpi);
    CHECK_EQ(tmpi.begin(),3);
    CHECK_NOTHROW(auto tmpw = tmpi);
    
    for (int i=0; i<10; i++){
        tst4.addElement(i);
    }
    auto tmpw = tmpi.begin();
    CHECK_EQ(*tmpw,0);
    ++tmpw;
    CHECK_EQ(*tmpw,9);
    ++tmpw;
    CHECK_EQ(*tmpw,1);
    ++tmpw;
    CHECK_EQ(*tmpw,8);
    ++tmpw;
    CHECK_EQ(*tmpw,2);
    ++tmpw;
    CHECK_EQ(*tmpw,7);
    ++tmpw;
    CHECK_EQ(*tmpw,3);
    ++tmpw;
    CHECK_EQ(*tmpw,6);
    ++tmpw;
    CHECK_EQ(*tmpw,4);
    ++tmpw;
    CHECK_EQ(*tmpw,5);
    ++tmpw;

for (int j=0;j<10;j++){
    tst4.removeElement(j);
}

    tst4.addElement(14);
    tst4.addElement(13);
    tst4.addElement(11);
    tst4.addElement(2);
    tst4.addElement(5);
    tst4.addElement(9);
    tst4.addElement(16);
    auto itti = tmpi.begin();
    CHECK_EQ(*++itti,14);
    CHECK_EQ(*++itti,16);
    CHECK_EQ(*++itti,13);
    CHECK_EQ(*++itti,9);
    CHECK_EQ(*++itti,11);
    CHECK_EQ(*++itti,2);
    CHECK_EQ(*itti,5);

    tst4.removeElement(16);
    tst4.removeElement(5);
    tst4.removeElement(2);
    // we should be left with this containet -> 14 13 11 9 
    auto bbt = tmpi.begin();
    CHECK_NOTHROW(bbt!=tmpi.begin());
    while (bbt!=tmpi.end()){
        if (*bbt==14){
            tst4.addElement(8);         // we should be left with this containet -> 14 13 11 9 8
            CHECK_EQ(*(++bbt),8);         //it should be the cross to the next element added at the end
            CHECK_EQ(*(++bbt),13);         //should skip the '9'
        }
        if (*bbt==11){
            tst4.addElement(1);
//if the number one is added, it should be only at the right end of the queue, where in a cross iteration we wont return to after 'visiting' the middle
            CHECK_NE(*(++bbt),1);           
        }
    }
    auto cdp = tmpi.begin();
    auto ser = tmpi.begin();
    CHECK_NOTHROW(cdp!=ser);                    //first check that compersion operators are saftey to use
    CHECK_NOTHROW(cdp>ser);
    CHECK_NOTHROW(cdp<ser);
    ++cdp;
    CHECK_GT(cdp,ser);                          //by traversal order each is smaller than the other element if it appears before
    ++ser;
    ++ser;
    CHECK_LT(cdp,ser);
    ++cdp;
    CHECK_EQ(ser,cdp);              
}

TEST_CASE("Prime iterator functionality"){
    MagicalContainer tst5;
    CHECK_NOTHROW((MagicalContainer::SideCrossIterator(tst5)));     //make sure its properly receive container
    MagicalContainer::SideCrossIterator tmpt(tst5);
    CHECK_NOTHROW((MagicalContainer::SideCrossIterator(tst5)));     //a check that more than one iterator can work above the same container
    tst5.addElement(4);
    CHECK_NOTHROW(tmpt.begin());
    CHECK_NOTHROW(tmpt.end());
    CHECK_NOTHROW(*tmpt);
    CHECK_EQ(tmpt.begin(),4);
    CHECK_NOTHROW(auto tmpk = tmpt);


}