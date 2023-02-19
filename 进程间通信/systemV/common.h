#ifndef __COMM_H__
#define __COMM_H__

#define PATH "/home/sht/test/进程间通信/systemV/common.h"
#define PRO_ID 22
#define SIZE 4096
#include <iostream>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

key_t getkey()
{
    int ret = ftok(PATH, PRO_ID);
    if (ret == -1)
    {
        perror("ftok");
        exit(2);
    }
    return ret;
}

int get_shm(key_t key)
{
    int shmid = shmget(key, SIZE, IPC_CREAT | 0600);
    if (shmid == -1)
    {
        perror("共享内存挂载失败");
        exit(3);
    }
    return shmid;
}

int creat_shm(key_t key)
{
    int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0600);
    if (shmid == -1)
    {
        perror("共享内存挂载失败");
        exit(3);
    }
    return shmid;
}

void destroy_shm(int shmid)
{
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("共享内存删除错误");
    }
}

#endif