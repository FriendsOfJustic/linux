#define _CRT_SECURE_NO_WARNINGS 1


#include"STL_queue.h"
#include<iostream>

using namespace std;


//namespace sht
//{
//    template<class T, class Con = std::deque<T> >
//    class queue
//
//    {
//
//    public:
//
//        queue()
//        {
//
//        }
//
//        void push(const T& x)
//        {
//            v.push_back(x);
//        }
//
//        void pop()
//        {
//            v.pop_front();
//        }
//
//        T& back()
//        {
//            return v.back();
//        }
//
//        const T& back()const
//        {
//            return v.back();
//        }
//
//        T& front()
//        {
//            return v.front;
//        }
//
//        const T& front()const
//        {
//            return v.front();
//        }
//
//        size_t size()const
//        {
//            return v.size();
//        }
//
//        bool empty()const
//        {
//            return v.empty();
//        }
//    private:
//
//        Con v;
//
//    };
//}

int main()
{
    sht::queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();

    while (!s.empty())
    {
        cout << s.front() << " ";
        s.pop();
    }
    return 0;

}