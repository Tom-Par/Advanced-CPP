#include <iostream>
#include <memory>
#include <utility>

class FuelTank {
    private:
    
    unsigned int fuel;
    std::mutex mutex;

    public:

    FuelTank(unsigned int initialFuel) : fuel(initialFuel) {}

    unsigned int refuel(unsigned int amount) 
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (fuel >= amount) {
            fuel -= amount;
            return amount;
        } else {
            return 0;
        }
    }
};

int main() {
    
}