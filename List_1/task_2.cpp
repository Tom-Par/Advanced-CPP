#include "vector.hpp"
#include <vector>

 //TODO
    template <typename T, typename T2>
    auto operator*(T const &a, T2 const &b) -> decltype(a[0] * b[0]) {
        if(a.size() != b.size()) {
           throw std::logic_error("Both sizes should me equal");
        }
        auto result = a[0] * b[0];
        for (int i =0; i< a.size(); i++)
        {
            result += a[i] * b[i];
        }
        return result;
    };

int main() {
    cpplab::vector<int> V;

    V.push(1);
    V.push(3);
    V.push(4);
    V.push(6);

    V.print();
    std::cout<< "Size: "<< V.size() << std::endl;
    std::cout<< "Capacity: "<< V.capacity() << std::endl;

    V.pop();
    V.print();

    std::cout<< "Size: "<< V.size() << std::endl;
    std::cout<< "Capacity: "<< V.capacity() << std::endl;
    
    V.push(7,0);
    V.print();

    V.push(12);

    V.push(10);
    std::cout<< "Size: "<< V.size() << std::endl;
    std::cout<< "Capacity: "<< V.capacity() << std::endl;

    V.get(6);
    V.get(0);

    V.pop();
    V.pop();

    //std::vector to test scalar multiplying 
    std::vector<int> W = {1,2,3};
    std::vector<float> W2 = {1.2,2.3,3.4};
    
    std::cout<<"W size: "<<W.size()<<std::endl;

    std::cout<< "W * V: "<< W * V <<std::endl;
    std::cout<<"W * W2: "<< W * W2 <<std::endl;
    std::cout<<"V * W2: "<< V * W2 <<std::endl;
    
}