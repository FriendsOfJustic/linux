#pragma once
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <queue>
#include <mutex>

#define NUM 10

template <class T, size_t N = NUM>
class Blockqueue
{
public:
    Blockqueue()
    {
        pthread_cond_init(&_p_cond, nullptr);
        pthread_cond_init(&_c_cond, nullptr);
        pthread_mutex_init(&_mutex, nullptr);
    }

    void push(const T &x)
    {
        pthread_mutex_lock(&_mutex);
        while (is_full()) // 如果队列满了就进入该循环进行挂起
        {
            pthread_cond_wait(&_p_cond, &_mutex);
        }

        // 走到这里代表队列一定不是满的
        _q.push(x);

        // 走到这里代表队列里一定有元素，可以唤醒消费者
        pthread_cond_signal(&_c_cond);
        pthread_mutex_unlock(&_mutex);
    }

    void pop(T *x)
    {
        pthread_mutex_lock(&_mutex);
        while (is_empty()) // 如果队列为空 执行此逻辑
        {
            pthread_cond_wait(&_c_cond, &_mutex);
        }

        T top = _q.front();
        // 消费数据
        //....
        *x = top;
        _q.pop();
        // 走到这里队列一定不是满的可以通知生产者继续生产
        pthread_cond_signal(&_p_cond);
        pthread_mutex_unlock(&_mutex);
    }

    bool is_full() // 判断是否满了
    {
        return (_q.size() == N);
    }

    bool is_empty() // 判断是否为空
    {
        return _q.empty();
    }

private:
    std::queue<T> _q;
    pthread_cond_t _p_cond;
    pthread_cond_t _c_cond;
    pthread_mutex_t _mutex;
};