#include <iostream>
#include "vectorV2.hpp"

//Structure to test emplace_back();
struct Pixel {
    int r, g, b;
    Pixel() : r(0), g(0) ,b(0) {}
    Pixel(int red, int green, int blue ) : r(red), g(green), b(blue) {}
};

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

    cpplab::vector<int> V4;
    V4.push(2);
    V4.push(5);

    cpplab::vector<int> V5 = std::move(V4);
    
    V4.print();
    V5.print();

    cpplab::vector<Pixel> V_Pixel;

    V_Pixel.emplace_back(2,5,8);
    V_Pixel.emplace_back(4,3,5);

    // V_Pixel.print();

    return 0;
    
}