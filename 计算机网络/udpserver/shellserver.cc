#include "udpserver.hpp"
#include <memory>
#include <stdio.h>

using namespace std;

void fun(int fd, sockaddr_in client, const char *message)
{
    cout << message << endl;

    FILE *ret = popen(message, "r");
    if (ret == nullptr)
    {
        cout << "popen error" << endl;
        exit(1);
    }

    char result[2048];
    int sz = fread(result, 1, 2048, ret);
    // fgets(result, 1024, ret);
    //  std::cout << inet_ntoa(client.sin_addr) << std::endl;
    //  std::cout << ntohs(client.sin_port) << std::endl;
    cout << sz << endl;
    result[sz] = '\0';
    // result[sz] = '\0';
    sz = sendto(fd, result, strlen(result), 0, (sockaddr *)&client, sizeof client);
    pclose(ret);
}

// server port

int main(int argc, char *argv[])
{
    shared_ptr<sht::udp_server> server = make_shared<sht::udp_server>(atoi(argv[1]));
    server->server_init(fun);
    server->run();
}
