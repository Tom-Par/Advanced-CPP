#include <iostream>

template <typename T> 
concept Number = requires(T a, T b) {a+b; a-b;};

template <Number N>
auto algo(const N& a, const N& b) {
    return a+b;
}

int main() {
    int x = 7;
    int y = 9;
    auto z = algo(x, y);
    std::cout << z << std::endl;

    std::string xx = "7";
    std::string yy = "9";
    auto zz = algo(xx, yy);
    std::cout << zz << std::endl;
}