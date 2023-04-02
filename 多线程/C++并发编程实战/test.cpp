#include <thread>
#include <iostream>
#include "ThreadGaurd.hpp"
#include <cstdio>
#include <unistd.h>
using namespace std;
void test1() // 测试 ThreadGaurd
{
    thread t([]() -> void
             { cout << "fuck you bitch!" << endl; });
    sht::ThreadGaurd g1(t);
    sht::ThreadGaurd g2(t);
}

class A
{
public:
    void fun1()
    {
        cout << "fun1" << endl;
    }

    static void fun2()
    {
        cout << "fun2" << endl;
    }
};

void test2() // 测试线程调用 类的成员函数
{
    A a;
    thread t1(&A::fun1, &a); // 调用非静态函数，需要传入函数指针 和 对象的this指针
    thread t2(A::fun2);      // 调用静态函数 由于其没有this指针 所以不用传入this指针

    t1.join();
    t2.join();
}

void *fun_test3(void *)
{
    // exit(1);
    /* while (1)
    {
        cout << "hello " << endl;
    } */

    // sleep(3);
    pthread_detach(pthread_self());
    int *p = new int[5]{1, 2, 3, 4, 5};
    return (void *)p;
}
void test3() // 博客 测试代码
{
    pthread_t t3 = pthread_self();
    pthread_t t1, t2;
    pthread_create(&t1, nullptr, fun_test3, nullptr);
    // pthread_create(&t2, nullptr, fun_test3, nullptr);

    // pthread_exit(nullptr);
    //  return;
    //  exit(1);
    /*  printf("0x%x\n", t1);
     printf("0x%x\n", t2);
     printf("0x%x\n", t3); */
    sleep(3);
    void *ret = nullptr;
    pthread_join(t1, &ret);
    for (int i = 0; i < 5; i++)
    {
        cout << ((int *)ret)[i] << endl;
    }

    // pthread_join(t2, nullptr);

    return;
}

int main()
{

    test3();
    // test2();
}
