
#include <iostream>
#include <random>
#include <time.h>
#include <unistd.h>

#include "ThreadPool.hpp"

using namespace std;

/* class task
{
    //随便设计任务
    int a;
    int b;

    task()
    :a(rand()),b(rand())
    {

    }

    int operator()()
    {
        return a + b;
    }
}; */

class A
{
public:
    void *operator()()
    {
        int *p = new int(a + b);
        cout << "我被执行了" << a << " + " << b << " = " << *p << endl;
        return (void *)p;
    }

    int a = rand() % 10;
    int b = rand() % 100;
};

int main()
{
    srand((unsigned int)time(nullptr));
    // sht::ThreadPool<task> *t = new sht::ThreadPool<task>();
    sht::ThreadPool<A> *t = sht::ThreadPool<A>::get_singleton(10);
    int num = 100;
    while (num--)
    {
        sleep(1);
        t->push(new A);
    }

    t->~ThreadPool();
}