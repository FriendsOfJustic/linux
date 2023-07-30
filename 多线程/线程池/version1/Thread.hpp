#include <iostream>
#include <cstring>
#include <pthread.h>
#include <string.h>
#include <functional>

namespace sht
{
    class Thread
    {
        typedef std::function<void *(void *)> func;

    public:
        struct pack
        {
            Thread *p;
            void *args;
        };

        Thread(func start, void *args, int number)
            : func_(start), args_(args), number_(number)
        {
            struct pack *a = new pack;
            a->args = args_;
            a->p = this;
            int ret = pthread_create(&tid_, nullptr, run, (void *)a);
        }

        static void *run(void *args) // 由于static成员函数没有const指针，所以不能调用普通成员函数。所以我们
        {                            // 这里选择将this指针和参数打包传进来
            pack *tmp = (pack *)args;
            // std::cout << "thread number: " << tmp->p->number_ << " is running" << std::endl;
            return tmp->p->func_(tmp->args);
        }

        void join()
        {
            try
            {
                int ret = pthread_join(tid_, &result_);
                if (ret != 0)
                    throw "内存回收失败";
            }
            catch (const char *message)
            {
                std::cout << message << std::endl;
            }
        }

        ~Thread()
        {
            // delete result_;
        }

    private:
        std::string name_;
        int number_;
        pthread_t tid_;
        func func_;
        void *args_;
        void *result_;
    };

} // namespace name
