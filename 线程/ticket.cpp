#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>

using namespace std;
#define NUMBER 5

int num = 100;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *buyticket(void *args)
{

    while (true)
    {
        pthread_mutex_lock(&mutex);
        if (num > 0)
        {
            printf("buyer%d : 抢到了第 %d 张票\n", *((int *)args), num--);
            pthread_mutex_unlock(&mutex);
            usleep(100); // 这个如果不加的话，会出现饥饿现象
        }
        else
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    printf("buyer%d 退出\n", *((int *)args));
}

int main()
{
    pthread_t buyer[NUMBER];

    for (int i = 0; i < NUMBER; i++)
    {
        int *p = new int(i);

        pthread_create(buyer + i, NULL, buyticket, (void *)p);
    }

    for (int i = 0; i < NUMBER; i++)
    {
        pthread_join(buyer[i], nullptr);
    }
}