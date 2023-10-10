#include "namespaces.hpp"
#include <vector>

int main() {
    cpplab::vector<int> V;

    V.push(1);
    V.push(3);
    V.push(4);
    V.push(6);

    V.print();

    V.pop();
    V.print();
    
    V.push(7,0);
    V.print();

    std::cout<< "Capacity: "<< V.getcapacity() << std::endl;
    std::cout<< "Size: "<< V.size() << std::endl;
    std::cout<< V.get(2) << std::endl;

    std::vector<int> W;
    std::vector<float> W2;
    W.push_back(1);
    W.push_back(2);
    W.push_back(3);

    W2.push_back(1.2);
    W2.push_back(2.2);
    W2.push_back(3.3);

}