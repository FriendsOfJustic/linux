#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <bits/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// 556 TCP测试端口 557 UDP测试端口
using namespace std;
// tcpcon port
int main(int args, char *argv[])
{
    if (args != 2)
    {
        cout << "输入参数有误" << endl;
        exit(1);
    }

    // 转换ip 和 端口 号为符合网络字节序的参数

    uint16_t port = htons((uint16_t)atoi(argv[1]));

    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1)
    {
        cout << "socket fail" << endl;
        exit(3);
    }
    sockaddr_in s;
    bzero(&s, sizeof s);
    s.sin_family = AF_INET;
    s.sin_port = port;
    s.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(fd, (struct sockaddr *)&s, sizeof(s));

    if (ret == -1)
    {
        perror("bind fail");
        exit(2);
    }
    sleep(10);
    cout << "开始监听" << endl;
    ret = listen(fd, 5);
    sockaddr_in client_sockaddr;
    socklen_t client_len;
    sleep(10);
    while (1)
    {
        int connfd = accept(fd, (sockaddr *)&client_sockaddr, &client_len);
        if (connfd == -1)
        {
            perror("accept fail");
        }

        cout << inet_ntoa(client_sockaddr.sin_addr) << endl;
        cout << ntohs(client_sockaddr.sin_port) << endl;

        sleep(10);
        close(connfd);
    }
    return 0;
}