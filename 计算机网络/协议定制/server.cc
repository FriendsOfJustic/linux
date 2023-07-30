#include "./tcpserver.hpp"
#include "protocol.hpp"
#include <string>
#include <memory>
#include <unistd.h>
#include <jsoncpp/json/json.h>

using namespace std;
// 如何确保从网络字节流里面读取到一个完整的数据，就需要序列化有一定的纠错能力
// 这个函数需要在 管道文件里面读取出一个完整的数据包，并把有效载荷返回
string GetDataGram(int fd)
{
    std::string inbuffer; // 一个大的缓冲区，读取数据知道读取到完整的数据报
    while (1)
    {
        char buffer[4096];
        int sz = read(fd, buffer, 4096);

        if (sz == 0)
        {
            cout << "链接关闭" << endl;
            return string();
        }

        inbuffer += buffer;
        int pos1 = inbuffer.find("$", 0);
        int pos2 = inbuffer.find("$", pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos)
        {
            cout << "传入数据出错" << endl;
            return string();
        }
        // 计算出数据包的长度
        sz = atoi(inbuffer.substr(pos1 + 1, pos2 - pos1 - 1).c_str());

        return inbuffer.substr(pos2 + 1, sz);
    }
}

// Response 输出型参数  Request 是入参  这个函数实际上是业务逻辑
void Service(Response &resp, const Request &req)
{
    switch (req._op)
    {
    case '+':
    {
        resp.z = req._x + req._y;
    }
    break;
    case '-':
    {
        resp.z = req._x - req._y;
    }
    break;
    case '*':
    {
        resp.z = req._x * req._y;
    }
    break;
    case '/':
    {
        if (req._y != 0)
            resp.z = req._x / req._y;
        else
            resp.respose_message = "invalidparam";
    }
    break;

    default:
        resp.respose_message = "invalidoperator";
        break;
    }
}
int callback(sockaddr_in client, sockaddr_in server, int fd, LogMessage _log)
{
    while (1)
    {
#ifdef MYPROTOCAL
        // 接收用户传来的 request
        std::string buffer = GetDataGram(fd);

        if (buffer.size() == 0)
        {
            _log("client关闭连接", NORMAL);
            break;
        }
        buffer[buffer.size()] = '\0';
        std::string mesg(buffer);
        cout << mesg << endl;
        // 反序列化用户传来的request
        Request r1;
        r1.Deserialize(mesg);
        cout << r1.to_string() << endl;
        // 执行业务逻辑
        Response resp;
        Service(resp, r1);

        // 将结果序列化发出
        string returnMessage;
        resp.Serialize(returnMessage);
        cout << resp.z << endl;
        int sz = write(fd, returnMessage.c_str(), returnMessage.size());
        if (sz == 0)
            _log("server发出0个字符", NORMAL);
#endif

#ifdef JSON
        Json::Reader reader;
        Json::Value obj;

        char Buffer[2048];

        int sz = read(fd, Buffer, sizeof(Buffer) - 1);
        Buffer[sz] = '\0';
        cout << Buffer << endl;
        if (sz == 0)
        {
            _log("读端关闭链接", NORMAL);
            break;
        }

        reader.parse(Buffer, obj);

        int x = obj["x"].asInt();
        int y = obj["y"].asInt();
        string op = obj["operator"].asString();
        int result = 0;
        switch (*(op.c_str()))
        {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
        {
            if (y == 0)
            {
                _log("输入参数不符合运算要求", FATAL);
                continue;
            }
            else
                result = x / y;
        }
        break;

        default:
        {
            _log("输入参数不符合运算要求", FATAL);
            continue;
            ;
        }
        break;
        }

        Json::Value reponse;
        Json::FastWriter w;

        reponse["退出码"] = "计算正确";
        reponse["result"] = result;

        string tranm = w.write(reponse);

        sz = write(fd, tranm.c_str(), tranm.size());
        if (sz == 0)
        {
            _log("输出错误", FATAL);
            return -1;
        }

#endif
    }
    return 0;
}
// server port
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        cout << "请输入正确参数" << endl;
        exit(1);
    }

    shared_ptr<sht::tcpserver> serv = make_shared<sht::tcpserver>(atoi(argv[1]), "/home/sht/test/计算机网络/Log/server.txt", callback);
    serv->init();
    serv->run();
    return 0;
}
