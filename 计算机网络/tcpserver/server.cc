#include "./tcpserver.hpp"
#include <string>
#include <memory>
#include <unistd.h>
#include "daemon.hpp"

using namespace std;

int callback(sockaddr_in client, sockaddr_in server, int fd, LogMessage _log)
{

    // 回调函数
    cout << "lllll" << endl;
    while (1)
    {
        char buffer[2048];
        int sz = read(fd, buffer, 2048);
        buffer[sz] = '\0';
        if (sz == 0)
        {
            _log("client关闭通信", NORMAL);
            break;
        }
        else
        {
            cout << buffer << endl;
            _log(buffer, PRINT);
            string msg = "收到";

            int ret_sz = write(fd, msg.c_str(), msg.size());

            if (ret_sz == 0)
            {
                _log("server返回结果失败", NORMAL);
                break;
            }
        }
    }
}

// server port
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        cout << "请输入正确参数" << endl;
        exit(1);
    }

    deamon();
    shared_ptr<sht::tcpserver> serv = make_shared<sht::tcpserver>(atoi(argv[1]), "/home/sht/test/计算机网络/Log/server.txt", callback);
    serv->init();
    serv->run();
    return 0;
}