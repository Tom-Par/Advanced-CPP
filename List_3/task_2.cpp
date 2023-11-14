#include "vectorV2.hpp"

//Structure to test emplace_back();
struct Pixel {
    int r, g, b;
    Pixel() : r(0), g(0) ,b(0) {}
    Pixel(int red, int green, int blue ) : r(red), g(green), b(blue) {}
};

int main() {
  cpplab::vector<Pixel> V_Pixel;

    V_Pixel.emplace_back(2,5,8);
    V_Pixel.emplace_back(4,3,5);

    V_Pixel.print2();

    return 0;
}