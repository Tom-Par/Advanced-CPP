#include <mutex>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <iostream>

class ThreadPool {
public:
    explicit ThreadPool(std::size_t numThreads) : stop_flag(false) {
        start(numThreads);
    }

    ~ThreadPool() {
        stop();
    }

    void add_task(std::function<double()> task) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            tasks.push(std::move(task));
        }
        condition_.notify_one();
    }

    double average() {
        std::lock_guard<std::mutex> lock(mutex_);
        double sum = 0.0;
        for (double result : results) {
            sum += result;
        }
        return results.empty() ? 0.0 : sum / results.size();
    }

private:
    void start(std::size_t numThreads) {
        for (std::size_t i = 0; i < numThreads; ++i) {
            threads.emplace_back([this] {
                while (true) {
                    std::function<double()> task;
                    {
                        std::unique_lock<std::mutex> lock(mutex_);
                        condition_.wait(lock, [this] { return stop_flag || !tasks.empty(); });
                        if (stop_flag && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    if (task) {
                        double result = task();
                        {
                            std::lock_guard<std::mutex> lock(mutex_);
                            results.push_back(result);
                        }
                    }
                }
            });
        }
    }

    void stop() noexcept {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            stop_flag = true;
        }
        condition_.notify_all();
        for (std::thread& thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

    std::vector<std::thread> threads;
    std::queue<std::function<double()>> tasks;
    std::vector<double> results;
    std::mutex mutex_;
    std::condition_variable condition_;
    bool stop_flag;
};

int main() {
    ThreadPool pool(10); // Utworzenie puli wątków z 4 wątkami

    // Dodanie zadań do puli
    for (int i = 0; i < 10; ++i) {
        pool.add_task([i] {
            return i * 4.0; // Przykładowe zadanie: zwraca podwójną wartość licznika
        });
    }

    // Oczekiwanie na zakończenie wszystkich zadań
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Poczekaj chwilę, aby zadania zostały wykonane

    // Obliczenie średniej wyników
    double avg = pool.average();
    std::cout << "Średnia wyników: " << avg << std::endl;

    return 0;
}
