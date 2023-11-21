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
    for (size_t i =0; i< a.size(); i++)
    {
        result += a[i] * b[i];
    }
    return result;
};

int main() {
    try {
        std::vector<float> v1f = {2.3,4.4,5.5,6.6};
        std::vector<float> v2f = {3.5,1.1,5.5,8.8};

        std::vector<int> v1a = {107, 111, 110, 105, 107 }; //"konik" ASCII code
        std::vector<int> v2a = {98, 97, 116, 111, 110}; //"batonik" ASCII code

        std::cout << v1f * v2f <<std::endl;
        std::cout << v1a * v2a << std::endl;
        
        // different type 
        // std::cout << v1f * v1a << std:: endl;

        // With the string type, our function converts string to code ASCII 
        // and then does the multiplication
        std::string s1 = "konik";
        std::string s2 = "baton";

        std::cout << s1*s2 <<std::endl;
    }
    catch(const std::exception& e) {
        std::cout<<e.what();
    }
}

