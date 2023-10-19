#include "cpplab.hpp"
#include <iostream>

int main() {
    std::cout << cpplab::hypercube<int, 4, 4>::get_volume() << std::endl;
    static_assert(cpplab::hypercube<int, 4, 4>::get_volume(),"Does not work during compilation time");
}