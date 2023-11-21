#include <iostream>
#include <thread>
#include <chrono>

void foo() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
    std::thread t1(foo);
    std::thread::id t1_id = t1.get_id();

    std::cout << "t1's id: " << t1_id<<'\n';

    t1.join();

    std::cout << "t1's id after join: " << t1.get_id()<<'\n';
}