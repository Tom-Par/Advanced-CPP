#include "namespaces.hpp"
#include <vector>



int main() {
    cpplab::vector<int> V;

    V.push(1);
    V.push(3);
    V.push(4);
    V.push(6);

    V.print();
    std::cout<< "Size: "<< V.get_size() << std::endl;
    std::cout<< "Capacity: "<< V.get_capacity() << std::endl;

    V.pop();
    V.print();

    std::cout<< "Size: "<< V.get_size() << std::endl;
    std::cout<< "Capacity: "<< V.get_capacity() << std::endl;
    
    V.push(7,0);
    V.print();

    V.push(12);

    V.push(10);
    std::cout<< "Size: "<< V.get_size() << std::endl;
    std::cout<< "Capacity: "<< V.get_capacity() << std::endl;

    V.get(6);
    V.get(0);

    //std::vector to test scalar multiplying 
    std::vector<int> W = {1,2,3};
    std::vector<float> W2 = {1.2,2.3,3.4};
 

    std::cout<<W.size()<<std::endl;

    std::vector<int> a{4, 5, 6};

    // std::cout<< V * a <<std::endl;
    
}