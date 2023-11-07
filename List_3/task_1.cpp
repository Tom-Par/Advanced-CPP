#include <iostream>
#include "vectorV2.hpp"

int main() {
     cpplab::vector<int> V;

    V.push(1);
    V.push(3);
    V.push(4);
    V.push(6);

    

    //Use of copy constructor
    cpplab::vector<int> V2 = V;
    cpplab::vector<int> V3;
    V3 = V;

    V.print();
    V2.print();
    V3.print();
    
    
}