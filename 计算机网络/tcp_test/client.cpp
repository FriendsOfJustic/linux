#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <bits/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// client port ip message
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "请输入正确参数" << endl;
        exit(1);
    }

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);
    cout << "开始连接" << endl;
    int ret = connect(fd, (sockaddr *)&server_addr, sizeof server_addr);
    if (ret == -1)
    {
        perror("connet fail");
    }

    sleep(20);

    close(fd);
    return 0;
}
