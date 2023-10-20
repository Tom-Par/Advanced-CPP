#include "cpplab.hpp"
#include <iostream>

int main() {
    int a = 4;
    float b = 1.2;

    const char *c = "cpp";
    const char *d = "lab";
    
    std::cout << cpplab::add(&a, &b) <<std::endl;
    std::cout << cpplab::add(c, d) << "\n";
    return 0;
}