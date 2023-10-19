#include "template_add.hpp"


main()
{
int a=5;
int b=4;
float c=4.65;
float d=7.78;
std::string str1 = "Jeden ";
std::string str2 = "Dwa ";


std::cout << add(a, b) <<std::endl;
std::cout << add(c,d) <<std::endl;
std::cout << add(str1,str2) <<std::endl;
std::cout << add(a,c) << std::endl;

//wyrażenie alias z wyrażeniem lambda (max)
std::cout << alias(b,c, [](auto b,auto c) {return b > c ? b : c;}) << std::endl;
//wyrażenie alias z operacją mnożenia
std::cout << alias(a, b, [](auto a,auto b) {return a*b;}) << std::endl;
}
