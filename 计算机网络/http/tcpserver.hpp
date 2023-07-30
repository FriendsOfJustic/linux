#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include "LogMessage.hpp"
#include <functional>
#include <string>
#include "ThreadPool.hpp"
#include "httpHeader.hpp"
#include <memory>
#include <unistd.h>

namespace sht
{
    // 创建线程池的任务
    class TcpTask : public sht::task
    {
    public:
        TcpTask(LogMessage log, sockaddr_in cli, sockaddr_in serv, int a, HttepHandler handler)
            : _log(log), client(cli), server(serv), fd(a), _handler(handler)
        {
        }
        void operator()()
        {
            // cout << fd << endl;
            char Buffer[4096 * 10];
            int sz = recv(fd, Buffer, 4096 * 10 - 1, 0);
            if (sz == 0)
                _log("客户端关闭链接", NORMAL);

            _log("收到请求字节数：\n" + to_string(sz), NORMAL);
            Buffer[sz] = '\0';
            _log("收到请求：\n" + string(Buffer), NORMAL);
            HttpRequest req(Buffer);
            req.Prase();
            HttpResponse resp;
            // cout << req.url << endl;
            if ((_handler.map).find(req.url) == (_handler.map).end())
            {
                // 没有找到，执行404方法
                _log("访问的页面并不存在", NORMAL);
                req.url = "/notfound.html";
                ((_handler.map)["/notfound.html"])(req, resp);
            }
            else
                ((_handler.map)[req.url])(req, resp);

            string responsestr = resp.generator();
            sz = write(fd, responsestr.c_str(), responsestr.size());
        }
        HttepHandler _handler;
        sockaddr_in client;
        sockaddr_in server;
        int fd;
        LogMessage &_log;
    };

    // 回调函数
    typedef std::function<int(sockaddr_in, sockaddr_in, int, LogMessage)> callback;

    // tcpserver
    class tcpserver
    {
    public:
        tcpserver(uint16_t port, const std::string path, HttepHandler &con)
            : _port(port), _log(path), controller(con)
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
                // std::cout << "监听成共" << std::endl;
                if (fd < 0)
                {
                    _log("建立链接失败", ERROR);
                }
                else
                {
                    // std::cout << "文件描述符" << fd << std::endl;
                    t = new TcpTask(_log, client, server_addr, fd, controller);
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
        HttepHandler controller;
    };
}