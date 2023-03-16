#include <signal.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void sigcb(int signum)
{
    cout << "接收到" << signum << "号信号" << endl;
    sleep(1);
}

int main()
{
    struct sigaction t;
    t.sa_handler = sigcb;
    sigaction(2, &t, nullptr);
    while (1)
    {
        cout << "running" << endl;
        sleep(2);
    }
    // int p = 1 / 0; // 触发硬件信号
    return 0;
}