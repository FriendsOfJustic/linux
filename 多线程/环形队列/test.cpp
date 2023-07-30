#include "RingQueue.hpp"
#include <thread>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

struct task
{
    task(int x, int y)
        : _x(x), _y(y)
    {
    }

    int operator()()
    {
        return _x + _y;
    }
    int _x;
    int _y;
};
void consumer(sht::RingQueue<task, 10> *q)
{
    while (true)
    {
        task *tmp = nullptr;
        q->pop(&tmp);
        cout << tmp->_x << " + " << tmp->_y << " = " << (*tmp)() << endl;
        delete tmp;
    }
}

void productor(sht::RingQueue<task, 10> *q)
{
    while (true)
    {
        int x = rand() % 10;
        int y = rand() % 50;

        task *p = new task(x, y);
        q->push(*p);
    }
}

int main()
{
    srand((unsigned int)time(nullptr));
    sht::RingQueue<task, 10> *q = new sht::RingQueue<task, 10>();
    thread t1(consumer, q);
    thread t2(consumer, q);

    thread t3(productor, q);
    thread t4(productor, q);

    t1.join();
    t2.join();
    return 0;
}