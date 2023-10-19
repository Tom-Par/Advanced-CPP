#include <cstring>
#include <iostream>


namespace cpplab {
//task 1
template <typename T1, typename T2>
auto add(T1 *a, T2 *b) -> decltype(*a + *b) {
    return *a + *b;
}

std::string add(const char *a, const char *b) {
    return std::string(a)+std::string(b);
}

//task 2
template <typename T, T side, int dimentions> 
class hypercube {
public:
    static constexpr T get_volume() {
        if (dimentions < 0)
                return -1;
            T volume = 0;
            for (int i = 0; i < dimentions; ++i)
                volume = (i == 0) ? side : volume * side;
            return volume;
        }
    };

}