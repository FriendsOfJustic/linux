#include "udpserver.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "UserManager.hpp"

using namespace std;

User_management table;

void fun(int fd, sockaddr_in client, const char *msg)
{
    string messages = msg;
    cout << msg << endl;
    if (table.is_user(client))
    {
        if (messages.find("online") != std::string::npos)
        {
            table.delete_user(client);
            return;
        }

        cout << "用户数：" << table.usermap.size();
        for (auto e : table.usermap)
        {
            string return_msg = "来自" + e.first + " #: " + msg;
            sendto(fd, return_msg.c_str(), strlen(return_msg.c_str()), 0, (sockaddr *)&e.second, sizeof e.second);
        }
    }
    else
    {
        if (messages.find("online") == std::string::npos)
        {
            char ret[] = "请先登录再发送消息";
            int sz = sendto(fd, ret, strlen(ret), 0, (sockaddr *)&client, sizeof client);
        }
        else
        {
            // 登录程序
            table.add_user(client);
            char ret[] = "登录成功";
            int sz = sendto(fd, ret, strlen(ret), 0, (sockaddr *)&client, sizeof client);
        }
    }
}

// chatserver port
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "输入参数错误" << endl;
        return 1;
    }
    shared_ptr<sht::udp_server> server = make_shared<sht::udp_server>(atoi(argv[1]));

    server->server_init(fun);
    server->run();
}