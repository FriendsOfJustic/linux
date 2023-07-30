// pthread_getconcurrency   //获取线程的最大并发数
#include <pthread.h>
#include <vector>
#include <queue>
#include <mutex>
#include <iostream>
#include <thread>

namespace sht
{
    class Task // 所有的任务都必须从这个类里面继承
    {
    public:
        virtual void operator()() = 0;
    };

    class ThreadPool
    {
    public:
        static void *fun(void *args)
        {
            ThreadPool *p = (ThreadPool *)args;
            while (true)
            {
                pthread_mutex_lock(&(p->mutex));
                while (p->task_queue.empty())
                {
                    pthread_cond_wait(&(p->cond), &(p->mutex));
                }
                Task *mission = p->task_queue.front();
                p->task_queue.pop();
                pthread_mutex_unlock(&(p->mutex));
                // 执行任务
                (*mission)();
            }
        }
        ThreadPool()
        {
            // 获取硬件的最大并发数
            int sz = std::thread::hardware_concurrency();
            std::cout << sz << std::endl;

            pool.resize(sz);
            for (int i = 0; i < sz; i++)
                pthread_create(&pool[i], nullptr, fun, (void *)this);

            pthread_cond_init(&cond, nullptr);
            pthread_mutex_init(&mutex, nullptr);
        }

        void push(Task *p)
        {
            pthread_mutex_lock(&mutex);
            task_queue.push(p);
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            return;
        }

    private:
        std::vector<pthread_t> pool;
        // 这里我们实现一个阻塞队列
        std::queue<Task *> task_queue;
        pthread_cond_t cond;
        pthread_mutex_t mutex;
    };
}