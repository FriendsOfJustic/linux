#include <iostream>
#include <string.h>
#include "udpserver.hpp"

using namespace std;

void usage()
{
    cout << "请输入ip地址" << endl;
    exit(1);
}

void fun1(int fd, sockaddr_in source_addr, const char *messages)
{

    std::cout << "[" << inet_ntoa(source_addr.sin_addr) << " : " << ntohs(source_addr.sin_port) << "]"
              << "#:";
    cout << messages << endl;
}

// udpserver port
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        usage();
    }
    string ip = argv[1];

    sht::udp_server *server = new sht::udp_server((uint16_t)atoi(argv[1]));
    server->server_init(fun1);
    server->run();
}