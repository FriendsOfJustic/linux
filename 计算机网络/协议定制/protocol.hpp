#include <string>
#include <cstring>
#include <string.h>
#include "LogMessage.hpp"
#include <functional>

// request格式
//  x op y
class Request
{

    // LogMessage log;

public:
    int _x;
    int _y;
    char _op;
    Request(int x = 0, int y = 0, char op = ' ')
        : _x(x), _y(y), _op(op)
    {
    }

    // 输出型参数    报文的格式为：$有效载荷的长度$有效载荷
    bool Serialize(std::string &param)
    {
        std::string result;
        result += std::to_string(_x) + " " + _op + " " + std::to_string(_y);
        result[result.size()] = '\0';
        int sz = result.size();

        result = "$" + std::to_string(sz) + "$" + result;
        param = std::move(result);
        return true;
    }

    bool Deserialize(const std::string &param)
    {
        // 寻找分隔符并开始切割
        int pos1 = param.find(" ", 0);
        if (pos1 == std::string::npos)
            return false;
        int pos2 = param.find(" ", pos1 + 1);
        if (pos2 == std::string::npos)
            return false;
        if (pos1 + 2 != pos2)
            return false;

        // 开始切分字符串
        std::string first = param.substr(0, pos1);
        _x = atoi(first.c_str());
        std::string op = param.substr(pos1 + 1, 1);
        _op = op[0];
        std::string second = param.substr(pos2 + 1);
        _y = atoi(second.c_str());

        return true;
    }

    std::string to_string()
    {
        return std::to_string(_x) + " " + _op + " " + std::to_string(_y);
    }
};

// Response格式
class Response
{

public:
    std::string respose_message;
    int z;

    Response(const std::string &msg = "sucess", int x = 0)
        : respose_message(msg), z(x)
    {
    }

    // 输出型参数
    bool Serialize(std::string &param)
    {
        std::string result;
        result += respose_message + " " + std::to_string(z);
        int sz = result.size();

        result = "$" + std::to_string(sz) + "$" + result;
        param = std::move(result);
        return true;
    }

    bool Deserialize(const std::string &param)
    {
        int pos = param.find(" ");
        if (pos == std::string::npos)
            return false;
        respose_message = param.substr(0, pos);
        std::string x = param.substr(pos + 1);
        z = atoi(x.c_str());
        return true;
    }

    std::string to_string()
    {
        return respose_message + " " + std::to_string(z);
    }
};
