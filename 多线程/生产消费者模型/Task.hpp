#include <iostream>
#include <functional>
#include <string.h>

class Task_Op // 把数据传递给加法计算线程
{
    // typedef std::function<int(int, int)> _func;
public:
    Task_Op(int x = 0, int y = 0)
        : _x(x), _y(y)
    {
    }
    int _x;
    int _y;
};

class Task_fp // 向文件传输线程传递数据
{
public:
    Task_fp(int x, int y, int result)
    {
        s = std::string("计算结果：") + std::to_string(x) + std::string(" + ") +
            std::to_string(y) + std::string(" = ") + std::to_string(result) + '\n';
    }

    std::string s;
};