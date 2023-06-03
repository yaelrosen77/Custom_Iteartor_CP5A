#include "doctest.h"
#include <stdexcept>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("A check that a new magical container is adequtely instantiated"){
    MagicalContainer
    CHECK_NOTHROW(MagicalContainer tmp());
    
}