#include <iostream>
using namespace std;
#include "Blockqueue.hpp"
#include <random>
#include <time.h>
void *productor(void *ags)
{
    Blockqueue<int> *q = (Blockqueue<int> *)ags;
    while (true)
    {
        int n = rand() % 10;
        q->push(n);
        cout << "productor 生产出了数据-> " << n << endl;
        fflush(stdout);
        sleep(1);
    }
}
void *consumer(void *ags)
{
    Blockqueue<int> *q = (Blockqueue<int> *)ags;
    while (true)
    {
        int result;
        q->pop(&result);
        cout << "consumer 拿到了数据-> " << result << endl;
        fflush(stdout);
    }
}

int main()
{
    srand((unsigned int)time(nullptr));
    Blockqueue<int> *q = new Blockqueue<int>;
    // 创建5个生产者
    pthread_t p[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(p + i, nullptr, productor, (void *)q);
    }

    // 创建5个消费者
    pthread_t c[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(c + i, nullptr, consumer, (void *)q);
        // cout << "1" << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(p[i], nullptr);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(c[i], nullptr);
    }
}