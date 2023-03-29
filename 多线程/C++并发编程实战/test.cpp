#include <thread>
#include <iostream>
#include "ThreadGaurd.hpp"
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

void test2()   //测试线程调用 类的成员函数
{
    A a;
    thread t1(&A::fun1, &a);   //调用非静态函数，需要传入函数指针 和 对象的this指针
    thread t2(A::fun2);        // 调用静态函数 由于其没有this指针 所以不用传入this指针

    t1.join();
    t2.join();
}

int main()
{
     
     
     test2();
}
