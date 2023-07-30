

#include <iostream>
#include "udpclient.hpp"

using namespace std;

void fun(int fd, sockaddr_in server_addr)
{
    std::string msg;
    getline(std::cin, msg);
    // std::cout << msg << std::endl;
    int ret = sendto(fd, msg.c_str(), msg.size(), 0, (sockaddr *)&server_addr, sizeof server_addr);
    // std::cout << ret << std::endl;
}
// udpclient port ip
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "输入错误" << endl;
        return 1;
    }

    sht::udpclient t(atoi(argv[1]), argv[2]);

    t.server_init(fun);
    t.run();
}