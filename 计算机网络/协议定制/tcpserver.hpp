#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "LogMessage.hpp"
#include <string>
#include <memory>
#include <unistd.h>
#include <functional>

namespace sht
{

    class tcpserver
    {
    public:
        typedef std::function<int(sockaddr_in, sockaddr_in, int, LogMessage)> callback;
        tcpserver(uint16_t port, const std::string path, callback func)
            : _port(port), _log(path), _func(func)
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

            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(_port);
            server_addr.sin_addr.s_addr = INADDR_ANY;
            int ret = bind(sock_fd, (sockaddr *)&server_addr, sizeof server_addr);
            if (ret == -1)
            {
                _log("bind fail", FATAL);
                exit(FATAL);
            }

            ret = listen(sock_fd, 10);
            if (ret == -1)
            {
                _log("listen fail", ERROR);
            }
        }

        void run()
        {
            while (1)
            {
                sockaddr_in client;
                socklen_t clientsz = 0;
                int fd = accept(sock_fd, (sockaddr *)&client, &clientsz);
                std::cout << "监听成共" << std::endl;
                if (fd < 0)
                {
                    _log("建立链接失败", ERROR);
                }
                else
                {
                    _func(client, server_addr, fd, _log);
                }
            }
        }

    private:
        int sock_fd;
        uint16_t _port;          // 端口号
        callback _func;          // 回调函数
        sockaddr_in server_addr; // 服务器的配置
        LogMessage _log;         // 日志
    };
}