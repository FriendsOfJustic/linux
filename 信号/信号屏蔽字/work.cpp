#include <signal.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    sigset_t t;
    sigemptyset(&t);
    sigaddset(&t, 2);
    sigaddset(&t, 40);

    sigprocmask(SIG_SETMASK, &t, nullptr);

    for (int i = 0; i < 5; i++)
    {
        cout << "发送2号信号" << endl;
        raise(2);
        sleep(1);

        cout << "发送40信号" << endl;
        raise(40);
        sleep(1);
    }
}