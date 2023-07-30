#pragma once
#include <string>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <functional>

#define NUM 1024

namespace sht
{

    class udp_server
    {

        enum fial
        {
            SOCKET_FAIL = 1,
            BIND_FAIL
        };

        // 定义回调函数类型    把 server 和 方法 解耦了 ，这样 就可以多个cc文件复用一个server文件
        typedef std::function<void(int, sockaddr_in, const char *)> callback_func;

    public:
        udp_server(std::uint16_t port)
            : _port(port)
        {
        }

        void server_init(const callback_func &fun)
        {
            _func = fun;
            fd = socket(AF_INET, SOCK_DGRAM, 0);

            if (fd == -1)
            {
                std::cout << strerror(errno);
                exit(SOCKET_FAIL);
            }

            uint16_t i_port = htons(_port);

            // uint32_t i_ip = htonl(inet_addr(_ip.c_str()));

            uint32_t i_ip = htonl(INADDR_ANY);
            sockaddr_in t;
            bzero(&t, sizeof t);
            t.sin_port = i_port;
            t.sin_family = AF_INET;
            t.sin_addr.s_addr = i_ip;
            // t.sin_addr.s_addr = htonl(inet_addr("101.42.42.187"));

            // std::cout << i_port << std::endl;
            // std::cout << i_ip << std::endl;

            int ret = bind(fd, (sockaddr *)&t, sizeof t);
            if (ret == -1)
            {
                std::cout << strerror(errno) << "2" << std::endl;
                exit(BIND_FAIL);
            }
        }

        void run()
        {
            while (flag)
            {
                char buffer[NUM];
                sockaddr_in source;
                socklen_t source_sz;

                int ret = recvfrom(fd, (void *)buffer, NUM, 0, (sockaddr *)&source, &source_sz);
                if (ret != 0)
                {
                    buffer[ret] = '\0';
                    // std::cout << buffer << std::endl;
                    // std::cout << ret << std::endl;
                    // std::cout << inet_ntoa(source.sin_addr) << std::endl;
                    // std::cout << ntohs(source.sin_port) << std::endl;

                    _func(fd, source, buffer); // 调用函数
                }
                else
                    std::cout << "无输出" << std::endl;
            }
        }
        void terminate()
        {
            flag = false;
        }

    private:
        int fd;
        std::function<void(int, sockaddr_in, const char *)> _func;
        volatile bool flag = true;
        std::uint16_t _port;
    };
} // namespace sht
