
#include <mutex>
#include <thread>
#include <stack>
namespace sht
{
    template <class T>
    class safe_stack
    {
    public:
        safe_stack() {}

        safe_stack(const safe_stack &x)
        {
            std::lock_guard<std::mutex> tmp(x.m);
            data = x.data;
        }

        int size()
        {
            std::lock_guard<std::mutex> tmp(m);
            return data.size();
        }

        bool empty()
        {
            std::lock_guard<std::mutex> tmp(m);
            return data.size();
        }

        void push(const T &x)
        {
            std::lock_guard<std::mutex> tmp(m);
            data.push(x);
        }

        void pop(T &x)
        {
            if (data.empty())
                throw "空栈pop";
            std::lock_guard<std::mutex> tmp(m);
            x = data.top();
            data.pop();
        }

        std::shared_ptr<T> safe_pop()
        {
            if (data.empty())
                throw "空栈pop";
            std::lock_guard<std::mutex> tmp(m);
            std::shared_ptr<T> p(data.top());
            data.pop();
            return p;
        }

    private:
        std::mutex m;
        std::stack<T> data;
    };

} // namespace sht
