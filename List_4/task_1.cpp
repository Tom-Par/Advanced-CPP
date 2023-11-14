#include <iostream>
#include <vector>

template <typename T>
concept Scalar = requires(T const a, T const b) { 
    {a[0] * b[0]} -> std::same_as<decltype(a[0] * b[0])>;
};

template <typename T>
requires Scalar<T>
auto operator*(T const &a, T const &b) {
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
    try {
        std::vector<int> v1 = {107, 111, 110, 105, 107 };
        std::vector<int> v2 = {98, 97, 116, 111, 110};

        std::cout << v1 * v2<<std::endl;

        std::string s1 = "konik";
        std::string s2 = "baton";

        std::cout << s1*s2 <<std::endl;
    }
    catch(const std::exception& e) {
        std::cout<<e.what();
    }
}

