#include <signal.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void sighandler(int signum)
{
    cout << "接收到" << signum << "号信号" << endl;
    sleep(1);
}

int main()
{
    signal(8, sighandler);
    cout << "running" << endl;
    sleep(2);
    int p = 1 / 0; // 触发硬件信号
    return 0;
}