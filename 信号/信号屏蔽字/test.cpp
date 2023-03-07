#include <signal.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void sighandler(int signum)
{
    cout << "接收到" << signum << "号信号" << endl;
    sigset_t t;
    sigpending(&t);

    for (int i = 1; i < 32; i++)
    {
        if (sigismember(&t, i))
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
    sleep(1);
}

void get_pending()
{
    while (1)
    {
        sigset_t t;
        sigpending(&t);

        for (int i = 1; i < 32; i++)
        {
            if (sigismember(&t, i))
                cout << "1";
            else
                cout << "0";
        }
        cout << endl;
        sleep(1);
    }
}
int main()
{
    sigset_t s;
    sigset_t olds;

    signal(2, sighandler);

    sigisemptyset(&s);
    sigaddset(&s, 2);
    sigprocmask(SIG_SETMASK, &s, &olds);

    get_pending();
}