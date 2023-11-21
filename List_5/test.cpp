#include <iostream>
#include <thread>

void workFunction(int* ptr, size_t times) {
    while(times--) {
        *ptr += 1;
    }
}

int main(int agrc, char const *argv[])
{
    int* numbers = new int[3];

    std::thread t1(workFunction, numbers, 500);
    std::thread t2(workFunction, numbers +1, 600);
    std::thread t3(workFunction, numbers +2, 700);

    t1.join();
    t2.join();
    t3.join();


    for(size_t i = 0; i<3; ++i) {
        std::cout << "Number Slot " << (int)i << " is " << (int)numbers[i] << std::endl;
    }

    delete[] numbers;
    return 0;
}