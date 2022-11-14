#include <thread>
#include <shared_mutex>
#include <vector>
#include <iostream>
using namespace std;

class Counter
{
public:
    std::shared_mutex mutex;
    int counter{0};
};

void writer(Counter &counter)
{
    std::unique_lock<std::shared_mutex> lock(counter.mutex);
    counter.counter++;
    cout << "writing: " << counter.counter << endl;
}

int reader(Counter &counter)
{
    std::shared_lock<std::shared_mutex> lock(counter.mutex);
    cout << "reading: " << counter.counter << endl;
    return counter.counter;
}

int main()
{
    Counter counter;
    std::vector<std::thread> readThreads;
    std::vector<std::thread> writeThreads;

    for (int i = 0; i < 100; i++)
    {
        readThreads.push_back(thread(reader, std::ref(counter)));
        if (i % 5 == 0)
        {
            writeThreads.push_back(thread(writer, std::ref(counter)));
        }
    }

    for (auto &t : readThreads)
        t.join();

    for (auto &t : writeThreads)
        t.join();
    return 0;
}