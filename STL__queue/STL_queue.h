#pragma once
#include<deque>
#include<stdlib.h>

namespace sht
{
    template<class T, class Con = std::deque<T> >
    class queue

    {

    public:

        queue()
        {

        }

        void push(const T& x)
        {
            v.push_back(x);
        }

        void pop()
        {
            v.pop_front();
        }

        T& back()
        {
            return v.back();
        }

        const T& back()const
        {
            return v.back();
        }

        T& front()
        {
            return v.front();
        }

        const T& front()const
        {
            return v.front();
        }

        size_t size()const
        {
            return v.size();
        }

        bool empty()const
        {
            return v.empty();
        }
    private:

        Con v;

    };
}

