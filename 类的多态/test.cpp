#include <iostream>
using namespace std;
/*
class A
{
public:
    virtual void func1()
    {
        cout << "A::i am func1" << endl;
    }

    void func2()
    {
        cout << "A::i am func2" << endl;
    }
};

class B : public A
{
public:
    void func1()
    {
        cout << "B::i am func1" << endl;
    }

    void func2()
    {
        cout << "B::i am func2" << endl;
    }
}; */

/* void test1()
{
    A *ptr1 = new A;
    A *ptr2 = new B;

    cout << "多态调用" << endl;
    ptr1->func1();
    ptr2->func1();

    cout << endl
         << "普通调用" << endl;
    ptr1->func2();
    ptr2->func2();
} */
class A

{

public:
    A() : m_iVal(0) { test(); }

    virtual void func() { std::cout << m_iVal << " "; }

    void test() { func(); }

public:
    int m_iVal;
};

class B : public A

{

public:
    B() { test(); }

    virtual void func()

    {

        ++m_iVal;

        std::cout << m_iVal << " ";
    }
};

void test2()
{
    B *p = new B;
    p->test();
    return;
}
int main()
{
    // test2();
    A *p = new B;

    p->test();

    return 0;
}