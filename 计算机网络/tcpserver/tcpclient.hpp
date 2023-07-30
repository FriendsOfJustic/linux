#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "LogMessage.hpp"
#include <functional>
#include <string>
#include <iostream>
#include <functional>
#include <unistd.h>

namespace sht
{

    class TcpClinent
    {
        typedef std::function<int(sockaddr_in, int, LogMessage &)> callback;

    public:
        TcpClinent(const std::string ip, uint16_t port, const std::string path, callback func)
            : _ip(ip), _port(port), _log(path), _func(func)
        {
        }

        void init()
        {
            sock_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (sock_fd == -1)
            {
                _log("creat socket fail", FATAL);
                exit(1);
            }

            std::cout << _port << std::endl;
        }

        void run()
        {
            sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(_port);
            server_addr.sin_addr.s_addr = inet_addr(_ip.c_str());
            int fd = connect(sock_fd, (sockaddr *)&server_addr, sizeof server_addr);
            std::cout << "connect success" << std::endl;
            if (fd == -1)
            {
                perror("connect");
                _log("connect fail", FATAL);
                exit(1);
            }
            else
            {
                _func(server_addr, sock_fd, _log);
            }
        }

        ~TcpClinent()
        {
            close(sock_fd); // 记得关闭
        }

    private:
        LogMessage _log;
        std::string _ip;
        uint16_t _port;
        callback _func;
        int sock_fd;
    };
} // namespace sht
