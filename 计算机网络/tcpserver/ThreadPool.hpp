#include <pthread.h>
#include <vector>
#include <list>
#include <semaphore.h>
#include <thread>

// 反应堆式 线程池

// 需要实现单例模式
// 需要用信号量实现
namespace sht
{
    class task
    {
    public:
        virtual void operator()() = 0;
    };

    class ThreadPool
    {

    public:
        static void *fun(void *args)
        {
            ThreadPool *_this = static_cast<ThreadPool *>(args);
            task *mission = nullptr;
            while (_this->flag)
            {
                // std::cout << "p" << (_this->task_queue).size() << std::endl;
                sem_wait(&(_this->sem));
                // 判断任务队列不能为0
                if ((_this->task_queue).size() != 0)
                {
                    pthread_mutex_lock(&(_this->mutex));
                    if ((_this->task_queue).size() != 0)
                    {
                        mission = (_this->task_queue).front();
                        (_this->task_queue).pop_front();
                    }
                    pthread_mutex_unlock(&(_this->mutex));
                    // 执行任务
                    (*mission)();
                }
            }
            return nullptr;
        }

        void push_task(task *t)
        {
            pthread_mutex_lock(&mutex);
            task_queue.push_back(t);
            // std::cout << task_queue.size() << std::endl;
            sem_post(&sem);
            pthread_mutex_unlock(&mutex);
        }

        static ThreadPool *get_threadpool()
        {
            if (singleton == nullptr)
            {
                pthread_mutex_lock(&pool_mutex);
                if (singleton == nullptr)
                {
                    singleton = new ThreadPool;
                }
                pthread_mutex_unlock(&pool_mutex);
            }
            return singleton;
        }

        static void destroy_threadpool()
        {
            if (singleton != nullptr)
            {
                pthread_mutex_lock(&pool_mutex);
                if (singleton != nullptr)
                {
                    singleton->~ThreadPool();
                }
                pthread_mutex_unlock(&pool_mutex);
            }
        }

    private:
        ThreadPool()
        {
            // std::cout << std::thread::hardware_concurrency() << std::endl;
            pool.resize(std::thread::hardware_concurrency());
            sem_init(&sem, 0, pool.size());
            pthread_mutex_init(&mutex, nullptr);
            for (int i = 0; i < pool.size(); i++)
            {
                pthread_create(&pool[i], nullptr, fun, (void *)this);
            }
        }

        ~ThreadPool()
        {
            flag = true;
            pthread_mutex_destroy(&mutex);
            sem_destroy(&sem);
        }
        static ThreadPool *singleton;
        static pthread_mutex_t pool_mutex;
        std::vector<pthread_t> pool;
        sem_t sem;                    // 信号量
        pthread_mutex_t mutex;        // 互斥锁
        std::list<task *> task_queue; // 任务队列
        bool flag = true;             // 终止线程池
    };

    ThreadPool *ThreadPool::singleton = nullptr;
    pthread_mutex_t ThreadPool::pool_mutex = PTHREAD_MUTEX_INITIALIZER;
} // namespace sht
