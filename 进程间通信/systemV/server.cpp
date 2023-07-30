
// server 负责申请共享内存 和 释放共享内存

#include "common.h"
using namespace std;

int main()
{
    key_t key = getkey();

    cout << "server get key: " << key << endl;

    int shmid = creat_shm(key);

    cout << "server get shmid: " << shmid << endl;

    char *buffer = (char *)shmat(shmid, NULL, 0);

    // 执行操作

    int count = 0;
    int pid = getpid();
    while (true)
    {
        snprintf(buffer, SIZE, "[%d] server[pid:%d] write to client: i love you\n", ++count, pid);
        sleep(1);
    }

    shmdt(buffer);

    destroy_shm(shmid);
}