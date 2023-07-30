#include "./tcpclient.hpp"
#include <iostream>
#include <memory>

using namespace std;
int callback(sockaddr_in server, int fd, LogMessage &_log)
{
    while (1)
    {
        cout << "ENTER#";
        std::string message;
        getline(std::cin, message);

        int sz = write(fd, message.c_str(), message.size());

        if (sz == -1)
        {
            _log("write 错误", FATAL);
            exit(1);
        }
        else
        {
            cout << sz << endl;
            char buffer[2048];
            sz = read(fd, buffer, 2048);
            buffer[sz] = '\0';
            std::cout << buffer << std::endl;
        }
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