
#include <iostream>
#include <random>
#include <time.h>
#include <unistd.h>

#include "./version3/ThreadPool.hpp"

using namespace std;

#define NUM 10

class A : public sht::task
{
public:
    void operator()()
    {
        c = a + b;
        cout << "我被执行了" << a << " + " << b << " = " << c << endl;
    }

    int a = rand() % 10;
    int b = rand() % 100;
    int c;
};

int main()
{
    srand((unsigned int)time(nullptr));
    // sht::ThreadPool<task> *t = new sht::ThreadPool<task>();
    sht::ThreadPool *p = sht::ThreadPool::get_threadpool();
    vector<A *> task_array;
    task_array.resize(NUM);
    for (int i = 0; i < NUM; i++)
    {
        task_array[i] = new A;
        // cout << "1" << endl;
        p->push_task(task_array[i]);
        // cout << "2" << endl;
        // sleep(1);
    }
    sleep(5);
    for (auto &e : task_array)
        cout << e->c << endl;

    return 0;
}