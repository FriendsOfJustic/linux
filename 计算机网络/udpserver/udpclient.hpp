#pragma once
#include <string>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <functional>

// client不需要绑定特定的端口，由系统自动给client自动分配端口和ip

namespace sht
{
    class udpclient
    {
        // 定义回调函数类型    把 server 和 方法 解耦了 ，这样 就可以多个cc文件复用一个server文件
        typedef std::function<void(int, sockaddr_in)> callback_func;

    public:
        udpclient(uint16_t port, std::string ip)
            : _port(port), _ip(ip)
        {
        }

        void server_init(const callback_func &fun)
        {
            _func = fun;
            fd = socket(AF_INET, SOCK_DGRAM, 0);
            if (fd == -1)
            {
                std::cout << strerror(errno) << "1" << std::endl;
                exit(1);
            }
        }

        void run()
        {
            sockaddr_in t;
            t.sin_family = AF_INET;
            t.sin_addr.s_addr = inet_addr(_ip.c_str());
            t.sin_port = htons(_port);
            // std::string msg;
            while (flag)
            {
                _func(fd, t);
            }
        }

        void terminate()
        {
            flag = false;
        }

    private:
        std::function<void(int, sockaddr_in)> _func;
        volatile bool flag = true;
        int fd;
        uint16_t _port;  // 输入的端口
        std::string _ip; // 输入的点分十进制ip
    };
} // namespace sht
