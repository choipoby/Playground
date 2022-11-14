#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;

struct Turn
{
    mutex mtx;
    condition_variable cv;
    bool pingTurn{true};
};
void ping(struct Turn &turn)
{
    while (true)
    {
        unique_lock<mutex> lock(turn.mtx);
        if (!turn.pingTurn)
        {
            turn.cv.wait(lock);
        }
        cout << "ping --> " << endl;
        turn.pingTurn = false;
        turn.cv.notify_all();
    }
}

void pong(struct Turn &turn)
{
    while (true)
    {
        unique_lock<mutex> lock(turn.mtx);
        if (turn.pingTurn)
        {
            turn.cv.wait(lock);
        }
        cout << "pong <--" << endl;
        turn.pingTurn = true;
        turn.cv.notify_all();
    }
}

int main()
{
    Turn turn;
    thread t1(ping, std::ref(turn));
    thread t2(pong, std::ref(turn));
    t1.join();
    t2.join();

    return 0;
}