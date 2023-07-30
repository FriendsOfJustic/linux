#include "udpclient.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "UserManager.hpp"

using namespace std;

User_management table;

void *thread_print(void *args)
{
    FILE *out = fopen("chatlog.txt", "a+");
    while (1)
    {
        FILE *out = fopen("chatlog.txt", "a+");
        int fd = *((int *)args);
        char buffer[4096];
        int sz = recvfrom(fd, buffer, 4098, 0, nullptr, nullptr);
        // cout << "收到消息#    ";
        buffer[sz] = '\n';
        fprintf(out, "收到消息：%s", buffer);
        // cout << buffer << endl;
        fclose(out);
    }
}

void fun(int fd, sockaddr_in server)
{
    pthread_t tid;
    pthread_create(&tid, nullptr, thread_print, (void *)&fd);

    // cout << "请输入群发消息# ";
    string msg;
    getline(cin, msg);
    int sz = sendto(fd, msg.c_str(), strlen(msg.c_str()), 0, (sockaddr *)&server, sizeof server);
}

// chatserver port ip
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "输入参数错误" << endl;
        return 1;
    }
    shared_ptr<sht::udpclient> client = make_shared<sht::udpclient>(atoi(argv[1]), argv[2]);
    cout << "1" << endl;
    client->server_init(fun);
    client->run();
}