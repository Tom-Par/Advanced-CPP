#include <iostream>
#include <list>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

class FuelTank {
private:
    unsigned int fuel;
    std::mutex mutex;

public:
    FuelTank(unsigned int initialFuel) : fuel(initialFuel) {}

    unsigned int refuel(unsigned int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (fuel >= amount) {
            fuel -= amount;
            return amount;
        } else {
            return 0;
        }
    }
};

class Engine {
private:
    std::list<std::shared_ptr<FuelTank>> fuelTanks;
    std::mutex fuelTanksMutex;
    std::thread fuelConsumptionThread;
    bool stopThread = false;
    std::mutex coutMutex;

public:
    Engine(std::chrono::milliseconds interval, unsigned int fuelAmount)
        : fuelConsumptionThread(&Engine::consumeFuel, this, interval, fuelAmount) {}

    ~Engine() {
        stopThread = true;
        fuelConsumptionThread.join();
    }

    void connectFuelTank(std::shared_ptr<FuelTank> tank) {
        std::lock_guard<std::mutex> lock(fuelTanksMutex);
        fuelTanks.push_back(tank);
    }
    
    void consumeFuel(std::chrono::milliseconds interval, unsigned int fuelAmount) {
        while (!stopThread) {
            std::this_thread::sleep_for(interval);

            std::shared_ptr<FuelTank> connectedTank;
            {
                std::lock_guard<std::mutex> lock(fuelTanksMutex);
                if (!fuelTanks.empty()) {
                    connectedTank = fuelTanks.front();
                }
            }

            if (connectedTank) {
                unsigned int consumedFuel = connectedTank->refuel(fuelAmount);
                if (consumedFuel == 0) {
                    std::lock_guard<std::mutex> lock(fuelTanksMutex);
                    fuelTanks.pop_front();
                } else {
                    std::lock_guard<std::mutex> coutLock(coutMutex);  // lock 
                    std::cout << "Engine consumed " << consumedFuel << " units of fuel." << std::endl;
                }
            } else {
                std::lock_guard<std::mutex> coutLock(coutMutex);  // lock 
                std::cout << "No connected fuel tanks available." << std::endl;
            }
        }
    }
};

int main() {
    // Create fuel tanks
    std::list<std::shared_ptr<FuelTank>> fuelTanks;
    for (int i = 0; i < 10; ++i) {
        fuelTanks.push_back(std::make_shared<FuelTank>(10 + i));
    }

    // Create engines
    Engine engine1(std::chrono::seconds(2), 5);
    Engine engine2(std::chrono::seconds(1), 1);
    Engine engine3(std::chrono::seconds(3), 2);

    // Connect fuel tanks to engines
    for (const auto& tank : fuelTanks) {
        engine1.connectFuelTank(tank);
        engine2.connectFuelTank(tank);
        engine3.connectFuelTank(tank);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}
