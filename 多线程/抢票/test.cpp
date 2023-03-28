#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "Thread.hpp"
#include <memory>
using namespace std;
#define NUM 10
void *function(void *args)
{
    char *buffer = (char *)args;
    for (int i = 0; i < NUM; i++)
    {
        cout << buffer << "正在执行任务" << endl;
        // fflush(stdout);
        // sleep(1);
    }
    char *ret = new char[100];
    snprintf(ret, 100, "%s 退出 被父进程回收", buffer);
    delete buffer;
    // cout << ret << endl;
    return (void *)ret;
}

void *getTicket(void *args)
{
    cout << "fuck you" << endl;
    cout << (const char *)args << endl;
}

void *fun(void *args)
{
    while (1)
    {
        cout << "son Thread LWP:" << pthread_self() << "is running"
             << "pid" << getpid() << endl;

        sleep(2);
    }

    return nullptr;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, fun, (void *)nullptr);

    int num = 5;
    while (num--)
    {
        cout << "main Thread LWP:" << pthread_self() << "is running"
             << "pid" << getpid() << endl;

        sleep(2);
    }

    pthread_exit(nullptr);

    /* pthread_t *tid = new pthread_t[NUM];
    for (int i = 0; i < NUM; i++)
    {
        char *buffer = new char[20];
        snprintf(buffer, 20, "线程 %d", i);
        pthread_create(tid + i, nullptr, function, (void *)buffer);
        cout << tid[i] << endl;
    }

    // sleep(5);
    // cout << "1" << endl;

    // sleep(10);
    for (int i = 0; i < NUM; i++)
    {
        void *p = nullptr;
        pthread_join(tid[i], &p);
        char *ret = (char *)p;
        if (ret == nullptr)
            cout << "nullptr" << endl;
        else
            cout << ret << endl;
        // cout << ret << endl;
        //  cout << (char *)*p << endl;
    } */

    // sht::Thread *p1 = new sht::Thread(getTicket, nullptr);
}
