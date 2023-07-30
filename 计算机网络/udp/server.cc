#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <cstring>

void Server()
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
    s.sin_addr.s_addr = INADDR_ANY;

    int ret2 = bind(ret1, (const sockaddr *)&s, sizeof(s));
    if (ret2 < 0)
    {
        std::cout << "绑定失败" << std::endl;
        return;
    }

    while (true)
    {
        FILE *fd = fopen("log.txt", "a+");
        char buffer[1024];
        sockaddr_in src_addr;
        socklen_t src_len = sizeof(src_addr);

        int sz = recvfrom(ret1, buffer, 1024, 0, (sockaddr *)&src_addr, &src_len);
        std::cout << "接收到字符：" << sz << std::endl;
        /*  std::cout << strlen(buffer) << std::endl;
         buffer[strlen(buffer)] = '\0';

         std::cout << buffer << std::endl;
         buffer[strlen(buffer)] = '\n'; */
        fputs(buffer, fd);
        fclose(fd);
    }
}

int main()
{
    Server();
}