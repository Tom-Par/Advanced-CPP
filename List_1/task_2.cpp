#include "namespaces.hpp"

int main() {
    cpplab::vector<int> V;

    V.push(1);
    V.push(3);
    V.push(4); 
    V.push(6);

    V.print();

    V.pop();
    V.print();
    
    std::cout<< "Capacity: "<< V.getcapacity() <<std::endl;
    std::cout<< "Size: "<<V.size() << std::endl;
}