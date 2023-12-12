#include <iostream>
#include <thread>
#include <mutex>    
#include <future>

int thread_id(){
    static int i = 0; 
    thread_local int id = ++i;
    return i;
}

void print_text(std::string text) {
    static std::mutex mut;
    std::lock_guard<std::mutex> lock(mut);
    std::cout << "Thread " << thread_id() << ": "<< text<<std::endl;
}

void foo1(std::launch fun) {
    auto f = std::async(fun, &print_text, "Jeden");
    f.get();
}

void foo2(std::launch fun) {
    auto f = std::async(fun, &print_text, "Dwa");
    foo1(fun);
    f.get();
}

void foo3(std::launch fun) {
    auto f = std::async(fun, &print_text, "Trzy");
    foo2(fun);
    f.get();
}

int main() {
    std::thread th1( &print_text, "Jeden");
    std::thread th2( &print_text, "Dwa");
    std::thread th3( &print_text, "Trzy");
    std::thread th4( &print_text, "Cztery");
    std::thread th5( &print_text, "Pięć");
    std::thread th6( &print_text, "Sześć");
    std::thread th7( &print_text, "Siedem");

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();

    std::cout<<"\n";
    
    foo3(std::launch::async);
    std::cout<<"\n";
    foo3(std::launch::deferred);
    
}