#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

void deamon()
{
    // 让自己能够处理一些信号——这里理论上是要屏蔽一些信号的、

    // 让自己不是进程组组长
    if (fork() > 0)
        _exit(1);

    setsid();

    // 守护进程是脱离终端的，处理一下标准输入和输出
    int fd = open("/dev/null", O_WRONLY, 666);

    if (fd < 0)
    {
        std::cout << "守护进程创建失败" << std::endl;
    }
    else
    {
        dup2(fd, 0);
        dup2(fd, 1);
        dup2(fd, 2);
    }
}