#include <mutex>
#include <thread>
#include <vector>

class ThreadPool
{
public:
    explicit ThreadPool(std::size_t numThreads)
    {
        start(numThreads);
    }

    ~ThreadPool()
    {
        stop();
    }


private:
    void start(std::size_t numThreads)
    {

    }

    void stop() noexcept
    {

    }
};
