#include "template_add_2.hpp"
#include <iostream>

int main() {
    int a = 4;
    float b = 1.2;

    const char *c = "cpp";
    const char *d = "lab";
    
    std::cout << add(&a, &b) <<std::endl;
    std::cout << add(c, d) << "\n";
    return 0;
}