#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>

void Client(char **argv)
{
    // 创建网络文件      IPV6     UDP协议看
    int ret1 = socket(AF_INET, SOCK_DGRAM, 0);

    if (ret1 == -1)
    {
        throw "创建socket失败";
    }

    sockaddr_in s;
    s.sin_port = htons((uint16_t)8080);
    s.sin_family = AF_INET;
    // s.sin_addr.s_addr= IP地址
    s.sin_addr.s_addr = inet_addr("101.42.42.187");

    // bind(ret1, (const sockaddr *)&s, sizeof s);
    while (true)
    {
        char buffer[1024];
        std::cin >> buffer;
        std::cout << strlen(buffer) << std::endl;
        int sz = sendto(ret1, buffer, std::strlen(buffer), 0, (sockaddr *)&s, sizeof(s));
        std::cout << "传输字符：" << sz << std::endl;
    }
}

int main(int argc, char **argv) // 0、输入参数  1、IP地址  2、端口号
{
    /* if (argc != 3)
    {
        std::cout << "输入错误" << std::endl;
        return 1;
    }
    else
    {
        Client(argv);
    } */
    Client(nullptr);
}