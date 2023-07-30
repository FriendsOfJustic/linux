#pragma once
#include <sys/epoll.h>
#include "LogMessage.hpp"
#include <unordered_map>
#include "TcpServer.hpp"
#include "Connection.hpp"
#include"Until.hpp"
#include <functional>
#include <string.h>
#include <err.h>
const int EPOLL_EVENT_SZ = 10;
const int TIME_COUT = 1000;
const int DEFAULT_PORT = 8080;
namespace sht
{
    using func = std::function<void(sht::Connection &)>; // 回调函数
    class epoll_server
    {

    public:
        explicit epoll_server(int num, uint16_t port = DEFAULT_PORT) : num_(num), server(new sht::TcpServer()), _port(port)
        {
        }

        void Create()
        {
            epoll_fd_ = epoll_create(num_);
            server->Sock(_port);
            server->Listen();
            epoll_event e;
            e.events = EPOLLIN | EPOLLET;
            e.data.fd = server->FD();
            if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, server->FD(), &e) != 0)
            {
                log_(ERROR, "epoll 事件添加失败");
            }
            log_(DEBUG, "socket fd: " + std::to_string(server->FD()));
        }

        void DeleteConnection(epoll_event& del_event,int fd)
        {
             connections_mapper_.erase(fd);
            if (epoll_ctl(epoll_fd_, EPOLL_CTL_DEL,fd, &del_event) != 0){
                  log_(ERROR, "epoll 事件删除失败");
                  std::abort();
            }
            close(fd);
            log_(INFO,"关闭文件描述符"+std::to_string(fd)+"完成");
        }
        void AddConnection()
        {
            while (true)
            {
                sht::Connection *newcon = new sht::Connection();
                int fd = server->Accept(newcon);
                if (fd > 0)
                {
                    epoll_event newevent;
                    newevent.data.fd = fd;
                    newevent.events = EPOLLIN | EPOLLET;
                    connections_mapper_[fd] = newcon;
                    SetNoneBlock(fd);
                    if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &newevent) != 0)
                    {
                        log_(ERROR, "epoll 事件添加失败");
                    }
                }
                else
                {
                    break;
                }
            }
        }

        // 对epoll 就绪队列中的事件进行分发
        // 1. 对事件类型进行 判断
        //
        void TaskDistribute(epoll_event *ready_queue,int queue_sz)
        {
            for (int i = 0; i < queue_sz; i++)
            {
                epoll_event cur_event = ready_queue[i];
                if (cur_event.events & EPOLLHUP || cur_event.events & EPOLLERR)
                {
                    // 将错误交给用户处理
                    cur_event.events = EPOLLIN;
                }

                if (cur_event.events & EPOLLIN)
                {
                    if (cur_event.data.fd == server->FD())
                    {
                        log_(INFO, "new connect coming!!!");
                        AddConnection();
                    }
                    else
                    {
                         log_(INFO, "message ready!"+std::to_string(cur_event.data.fd));
                         int ret=connections_mapper_[cur_event.data.fd]->RecverHandler();
                         if(ret==1){
                            DeleteConnection(cur_event,cur_event.data.fd);
                         }else{
                            log_(INFO,"client # "+connections_mapper_[cur_event.data.fd]->recvbuffer);
                         }
                    }
                }
                else if (cur_event.events & EPOLLOUT)
                {
                }
            }
        }

        // 循环访问事务是否有就绪的
        void Loop()
        {
            while (true)
            {
                log_(INFO, "polling!"+std::to_string(connections_mapper_.size()));
                epoll_event *wait_queue = new epoll_event[EPOLL_EVENT_SZ];
                int ret = epoll_wait(epoll_fd_, wait_queue, EPOLL_EVENT_SZ, TIME_COUT);
                if (ret > 0)
                {
                    TaskDistribute(wait_queue,ret);
                }
                else if (ret == 0)
                {
                    log_(INFO, "no event happen!");
                }
                else
                {
                    log_(FATAL, "epoll error->" + std::string(strerror(errno)));
                    std::abort();
                }
            }
        }

    private:
        TcpServer *server;
        uint16_t _port;
        int num_; /// epol模型的参数数
        int epoll_fd_;
        int max_events_;
        int timeout_;
        std::unordered_map<int, sht::Connection *> connections_mapper_; // 服务器建立链接的mapper  key: 文件描述符
        LogMessage log_;                                                // value: 链接信息结构体
    };
} // namespace sht
