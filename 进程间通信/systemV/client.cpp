
#include "common.h"
using namespace std;

int main()
{
    key_t key = getkey();

    cout << "client get key: " << key << endl;

    sleep(3);
    int shmid = get_shm(key);

    cout << "client get shmid: " << shmid << endl;

    char *buffer = (char *)shmat(shmid, NULL, 0);

    // 执行操作

    while (true)
    {
        printf(buffer);
        sleep(1);
    }

    shmdt(buffer);

    destroy_shm(shmid);

    destroy_shm(shmid);
}