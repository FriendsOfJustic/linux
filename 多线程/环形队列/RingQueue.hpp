#include <queue>
#include <semaphore.h>
#include <vector>
#include <mutex>
#include <iostream>

// 要搞清楚 环形队列和阻塞队列 到底在哪里不同
// 阻塞队列 是 先加锁 在 进入临界资源进行判断，这样如果队列满了，碰巧这一短时间都是生产者线程竞争成功
// 那么CPU 就会一直在做无用功（加锁、判断不满足、进入条件变量下等待并解锁）

// 而环形队列 在生成对象之就对临界资源进行了划分 这样临界资源的粒度更小，生产者和消费者只要不是访问同一个
// 小块就不会出现线程安全问题，这样就可以实现生产者和消费者同时访问临界资源；而这一点是阻塞队列无法达到的

namespace sht
{
    template <class T, size_t N>
    class RingQueue
    {
    public:
        RingQueue(int sz = 0)
            : p_cur(0), c_cur(0)
        {
            // 初始化信号量
            std::cout << N << std::endl;
            _array.resize(N);
            sem_init(&p_sem, 0, 0);
            sem_init(&c_sem, 0, N);
            pthread_mutex_init(&p_mutex, nullptr);
            pthread_mutex_init(&c_mutex, nullptr);
        }

        // 对PV操作进行封装

        // P操作：申请资源 == 计数器--
        void P(sem_t &x)
        {
            // 阻塞式申请
            int ret = sem_wait(&x);
        }

        // V操作：释放资源 == 计数器++
        void V(sem_t &x)
        {
            int ret = sem_post(&x);
        }

        void push(T &x)
        {
            P(c_sem);
            // 为什么这里要加锁？ ——申请到信号量只代表队列里面有空间，但是哪个空间有可能会冲突
            pthread_mutex_lock(&p_mutex);
            _array[p_cur++] = &x;
            p_cur %= N;
            pthread_mutex_unlock(&p_mutex);
            V(p_sem);
        }

        void pop(T **x)
        {
            P(p_sem);
            pthread_mutex_lock(&c_mutex);
            *x = _array[c_cur++];
            c_cur %= N;
            pthread_mutex_unlock(&c_mutex);
            V(c_sem);
        }

    private:
        std::vector<T *> _array;
        sem_t p_sem; // 队列中已经被占有的空间
        sem_t c_sem; // 队列中空余的空间
        int p_cur;
        int c_cur;
        pthread_mutex_t p_mutex; // 生产者的锁
        pthread_mutex_t c_mutex; // 消费者的锁
    };
}