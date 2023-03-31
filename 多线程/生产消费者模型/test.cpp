#include <iostream>
#include "Blockqueue.hpp"
#include <random>
#include <time.h>
#include "Task.hpp"
#include <memory>
using namespace std;
#define STATICS_NUM 1000

namespace sht
{
    struct Queue
    {
        Queue(Blockqueue<Task_Op *> *q1, Blockqueue<Task_fp *> *q2)
            : _q1(q1), _q2(q2)
        {
        }

        ~Queue()
        {
            delete _q1;
            delete _q2;
        }
        Blockqueue<Task_Op *> *_q1;
        Blockqueue<Task_fp *> *_q2;
    };
}
void *productor(void *ags)
{
    sht::Queue *q = (sht::Queue *)ags;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < STATICS_NUM; i++)
    {
        int x = rand() % 10;
        int y = rand() % 100;
        // cout << x << " " << y << endl;
        Task_Op *tmp = new Task_Op(x, y);

        q->_q1->push(tmp);
        // cout << "1" << endl;
    }
    return nullptr;
}
void *calculator(void *ags)
{
    sht::Queue *q = (sht::Queue *)ags;
    for (int i = 0; i < STATICS_NUM; i++)
    {
        int result;
        Task_Op *p = nullptr;
        q->_q1->pop(&p);

        // 使用智能指针接收内存
        shared_ptr<Task_Op> ptr(p);

        result = ptr->_x + ptr->_y;
        Task_fp *tmp = new Task_fp(ptr->_x, ptr->_y, result);
        // delete p;
        q->_q2->push(tmp);
        // cout << "2" << endl;
    }
    return nullptr;
}

void *filewrite(void *ags)
{

    sht::Queue *q = (sht::Queue *)ags;

    FILE *fd = fopen("log.txt", "a+");
    for (int i = 0; i < STATICS_NUM; i++)
    {
        Task_fp *p = nullptr;

        q->_q2->pop(&p);
        // 使用智能指针接收内存空间
        shared_ptr<Task_fp> ptr(p);

        // 移动赋值节省
        string tmp = move(ptr->s);

        // delete p;   使用智能指针就不用手动析构了

        // 下面执行文件写入

        fputs(tmp.c_str(), fd);
        // cout << "3" << endl;
    }
    fclose(fd);
    return nullptr;
}

int main()
{

    Blockqueue<Task_Op *> *q1 = new Blockqueue<Task_Op *>;
    Blockqueue<Task_fp *> *q2 = new Blockqueue<Task_fp *>;
    sht::Queue q(q1, q2);

    // 创建5个数据生产线程
    pthread_t p[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(p + i, nullptr, productor, (void *)&q);
    }

    // 创建5个计算线程
    pthread_t c[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(c + i, nullptr, calculator, (void *)&q);
        // cout << "1" << endl;
    }

    // 创建5个文件写入线程
    pthread_t f[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(f + i, nullptr, filewrite, (void *)&q);
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

    for (int i = 0; i < 5; i++)
    {
        pthread_join(f[i], nullptr);
    }
}