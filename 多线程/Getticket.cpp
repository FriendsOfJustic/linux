#include "Thread.hpp"
#include <iostream>
#include <unistd.h>
#include <memory>
int ticket_number = 1000;
using namespace std;

void *getticket(void *args)
{
    while (true)
    {
        if (ticket_number > 0)
        {
            usleep(9000);
            cout << (const char *)args << " 剩余票数：" << ticket_number << endl;
            --ticket_number;
            fflush(stdout);
        }
        else
            break;
    }

    return 0;
}

int main()
{

    std::unique_ptr<sht::Thread> thread1(new sht::Thread(getticket, (void *)"user1", 1));
    std::unique_ptr<sht::Thread> thread2(new sht::Thread(getticket, (void *)"user2", 2));
    std::unique_ptr<sht::Thread> thread3(new sht::Thread(getticket, (void *)"user3", 3));
    std::unique_ptr<sht::Thread> thread4(new sht::Thread(getticket, (void *)"user4", 4));
    std::unique_ptr<sht::Thread> thread5(new sht::Thread(getticket, (void *)"user5", 5));
    std::unique_ptr<sht::Thread> thread6(new sht::Thread(getticket, (void *)"user6", 6));

    thread1->join();
    thread2->join();
    thread3->join();
    thread4->join();
    thread5->join();
    thread6->join();
}