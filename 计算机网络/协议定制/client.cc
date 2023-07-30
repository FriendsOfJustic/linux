#include "./tcpclient.hpp"
#include <iostream>
#include <memory>
#include "protocol.hpp"

#include <jsoncpp/json/json.h>
using namespace std;

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
int callback(sockaddr_in server, int fd, LogMessage &_log)
{
    while (1)
    {

#ifdef MYPROTOCAL
        Request req;
        // 用户输入参数
        cout << "first: ";
        cin >> req._x;
        cout << "second: ";
        cin >> req._y;
        cout << "operator: ";
        cin >> req._op;
        // request系列化
        string serial;
        req.Serialize(serial);
        cout << serial << endl;
        // 向server发送request

        int sz = write(fd, serial.c_str(), serial.size());
        if (sz == 0)
        {
            _log("server退出", FATAL);
            return 1;
        }
        // 读取Response
        std::string buffer = GetDataGram(fd);
        if (buffer.size() == 0)
        {
            _log("server退出", FATAL);
            return 1;
        }

        buffer[buffer.size()] = '\0';
        string mesg(buffer);

        // Response反序列化
        Response resp;
        resp.Deserialize(mesg);

        cout << resp.to_string() << endl;
#endif

#ifdef JSON
        Json::Value resq;
        int x, y;
        string op;
        cout << "first: ";
        cin >> x;
        cout << "second: ";
        cin >> y;
        cout << "operator: ";
        cin >> op;

        resq["x"] = x;
        resq["y"] = y;
        resq["operator"] = op;
        Json::FastWriter w;
        Json::Reader r;

        string ReqString = w.write(resq);
        int sz = write(fd, ReqString.c_str(), ReqString.size());
        if (sz == 0)
        {
            _log("输出错误", FATAL);
            return -1;
        }

        Json::Value Resp;
        char Buffer[2048];

        sz = read(fd, Buffer, sizeof(Buffer) - 1);
        if (sz == 0)
        {
            _log("server关闭", FATAL);
            return -1;
        }
        Buffer[sz] = '\0';
        if (sz == 0)
        {
            _log("读端关闭链接", NORMAL);
            break;
        }

        r.parse(Buffer, Resp);

        string exitcode = Resp["退出码"].asString();
        int result = Resp["result"].asInt();
        cout << exitcode << "____" << result << endl;

#endif
    }
}

// main port ip
int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cout << "请输入正确的参数" << endl;
        exit(1);
    }
    shared_ptr<sht::TcpClinent> ptr = make_shared<sht::TcpClinent>(argv[2], atoi(argv[1]), "/home/sht/test/计算机网络/Log/client.txt", callback);
    ptr->init();
    ptr->run();
}