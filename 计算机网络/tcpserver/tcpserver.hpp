#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "LogMessage.hpp"
#include <functional>
#include <string>
#include "ThreadPool.hpp"
#include <memory>
#include <unistd.h>

namespace sht
{
    // 创建线程池的任务
    class TcpTask : public sht::task
    {
    public:
        TcpTask(LogMessage log, sockaddr_in cli, sockaddr_in serv, int a, std::function<int(sockaddr_in, sockaddr_in, int, LogMessage)> fun)
            : _log(log), client(cli), server(serv), fd(a), callback(fun)
        {
        }
        void operator()()
        {
            std::cout << "kkkk" << std::endl;
            callback(client, server, fd, _log);
        }

        std::function<int(sockaddr_in, sockaddr_in, int, LogMessage)> callback;
        sockaddr_in client;
        sockaddr_in server;
        int fd;
        LogMessage &_log;
    };
    typedef std::function<int(sockaddr_in, sockaddr_in, int, LogMessage)> callback;
    class tcpserver
    {
    public:
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
            sht::ThreadPool *pool = ThreadPool::get_threadpool();
            TcpTask *t = nullptr;
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
                    std::cout << fd << std::endl;

                    t = new TcpTask(_log, client, server_addr, fd, _func);
                    pool->push_task(t);
                    
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