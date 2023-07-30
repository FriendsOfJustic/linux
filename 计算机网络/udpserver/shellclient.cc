#include "udpclient.hpp"
#include <memory>
using namespace std;

// 回调函数的定义
void fun(int fd, sockaddr_in server)
{
    string cmdline;
    char buffer[2048];
    cout << "输入指令#";
    getline(cin, cmdline);
    sendto(fd, cmdline.c_str(), strlen(cmdline.c_str()), 0, (sockaddr *)&server, sizeof server);
    int sz = recvfrom(fd, buffer, 2048, 0, nullptr, nullptr);
    buffer[sz] = '\0';
    cout << sz << endl;

    cout << buffer << endl;
}

// client port ip

int main(int argc, char *argv[])
{

    shared_ptr<sht::udpclient> client = make_shared<sht::udpclient>(atoi(argv[1]), argv[2]);
    client->server_init(fun);
    client->run();
}
