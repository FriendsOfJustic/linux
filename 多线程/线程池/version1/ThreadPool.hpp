#include <queue>
#include <pthread.h>
#include <vector>
#include "Thread.hpp"
#include <iostream>

namespace sht
{
    template <class task>
    class ThreadPool
    {
        static void *fun(void *args)
        {
            ThreadPool<task> *t = static_cast<ThreadPool<task> *>(args);
            // std::cout << "7" << (t->task_queue).size() << std::endl;
            //  fflush(stdout);
            task *m = nullptr;
            while (true) // 重复的向任务队列里面去申请任务
            {
                if (!(t->task_queue).empty())
                {
                    pthread_mutex_lock(&(t->mutex));
                    while ((t->task_queue).empty())
                    {
                        // std::cout << (t->task_queue).size() << std::endl;
                        pthread_cond_wait(&(t->cond), &(t->mutex));
                        // std::cout << (t->task_queue).size() << std::endl;
                    }
                    // std::cout << "3" << std::endl;
                    m = (t->task_queue).front();
                    (t->task_queue).pop();
                    pthread_mutex_unlock(&(t->mutex));
                    (m->operator())();
                    delete m;
                }
            }
            return nullptr;
        }

        ThreadPool(const ThreadPool &x) = delete;
        void operator=(const ThreadPool &x) = delete;

        // 单例模式并不是把构造函数删除而是把构造函数隐藏

        ThreadPool(int NUM)
        {
            tid.resize(NUM);
            for (int i = 0; i < NUM; i++)
            {
                // std::cout << "4" << std::endl;
                pthread_create(&tid[i], nullptr, fun, (void *)this);
            }
            // std::cout << "1" << std::endl;
            pthread_mutex_init(&mutex, nullptr);
            pthread_cond_init(&cond, nullptr);
        }

    public:
        void push(task *x)
        {
            pthread_mutex_lock(&mutex);
            // std::cout << "2" << std::endl;
            task_queue.push(x);
            // std::cout << ((task_queue.front())->operator())();
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            // std::cout << "4" << std::endl;

            return;
        }

        ~ThreadPool()
        {
            for (int i = 0; i < tid.size(); i++)
            {
                pthread_cancel(tid[i]);
            }
            for (int i = 0; i < tid.size(); i++)
            {
                pthread_join(tid[i], nullptr);
            }
        }

        static ThreadPool<task> *get_singleton(int num)
        {
            pthread_mutex_init(&pool_mutex, nullptr);
            // 一定要搞清楚这里为什么要加锁！！！！
            pthread_mutex_lock(&pool_mutex);
            if (singleton == nullptr)
            {
                singleton = new ThreadPool(num);
            }
            pthread_mutex_unlock(&pool_mutex);
            return singleton;
        }

        static ThreadPool<task> *singleton; // 单例模式中的懒汉模式
    private:
        std::vector<pthread_t> tid;    // 存储线程的数组
        std::queue<task *> task_queue; // 任务队列
        pthread_mutex_t mutex;         // 任务锁
        pthread_cond_t cond;           // 条件变量

        static pthread_mutex_t pool_mutex; // 防止单例的线程池被创建了两次
    };

    template <class T>
    ThreadPool<T> *ThreadPool<T>::singleton = nullptr;

    template <class T>
    pthread_mutex_t ThreadPool<T>::pool_mutex;
}
