#include <cstring>
#include <iostream>

template <typename T1, typename T2>
auto add(T1 *a, T2 *b) -> decltype(*a + *b) {
    return *a + *b;
}

auto add(const char *a, const char *b) -> const char * {
    char *result = new char[strlen(a)+strlen(b)];
    strcpy(result, a);
    strcpy(result, b);
    return result;
}