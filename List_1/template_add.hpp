#include <iostream>

template<typename T1, typename T2>
auto add( T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

template<typename T1, typename T2, typename function>
auto alias(T1 a, T2 b, function operation) -> decltype(operation(a, b))
{
    return operation(a, b);
}