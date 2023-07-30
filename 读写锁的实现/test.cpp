#include "/home/sht/test/读写锁的实现/version2/rwlock.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>

using namespace std;

sht::sht_rwlock rwlock;
volatile int x = 0;

void write_func()
{
    rwlock.sht_rwlock_wrlock();
    x++;
    cout << "Write: " << x << endl;
    rwlock.sht_rwlock_unlock();
}

void read_func()
{
    usleep(100);
    rwlock.sht_rwlock_rdlock();
    cout << "Read: " << x << endl;
    rwlock.sht_rwlock_unlock();
}

int main()
{
    rwlock.sht_rwlock_init();
    vector<thread> w_pool;
    vector<thread> r_pool;

    for (int i = 0; i < 200; i++)
    {
        r_pool.push_back(thread(read_func));
    }

    for (int i = 0; i < 200; i++)
    {
        w_pool.push_back(thread(write_func));
    }

    for (auto &e : w_pool)
        e.join();
    for (auto &e : r_pool)
        e.join();
}
