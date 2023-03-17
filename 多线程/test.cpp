#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;
#define NUM 1
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

int main()
{
    pthread_t *tid = new pthread_t[NUM];
    for (int i = 0; i < NUM; i++)
    {
        char *buffer = new char[20];
        snprintf(buffer, 20, "线程 %d", i);
        pthread_create(tid + i, nullptr, function, (void *)buffer);
        cout << tid[i] << endl;
    }

    sleep(5);
    cout << "1" << endl;
    void **p = nullptr;
    pthread_join(tid[0], p);
    if (*p != nullptr)
        cout << (char *)*p << endl;

    // sleep(10);
    /* for (int i = 0; i < NUM; i++)
    {
        void **p = nullptr;
        pthread_join(tid[i], p);
        char *ret = (char *)*p;
        if (ret == nullptr)
            cout << "nullptr" << endl;
        else
            cout << ret << endl;
        // cout << ret << endl;
        //  cout << (char *)*p << endl;
    } */
}
