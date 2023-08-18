#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <vector>
#include "LogMessage.hpp"
#include <unordered_set>
#include<dirent.h>

namespace sht
{
#ifndef EPOLL_CONN
#define EPOLL_CONN
    const int EXPECT_SZ = 3;
    const char *ROOT_PATH = "./rescource";
    class Connection
    {
    private:
        // 将http 请求的静态资源注册到 tcpserver中
        void RegisterStaticRescource(const char *path)
        {
            DIR *dir;
            struct dirent *ptr;
            dir = opendir(path);
            if (dir == nullptr)
            {
                _log(ERROR, "打开目录失败");
                std::abort();
            }
            while ((ptr = readdir(dir)) != nullptr)
            {
                if (ptr->d_name[0] == '.')
                {
                    continue;
                }
                else
                {
                    static_resource.insert(ptr->d_name);
                }
            }
        }

        public:
            Connection(const char* _path=ROOT_PATH)
            {
                _log(INFO, "IN AddConnection");
                RegisterStaticRescource(_path);
            }
            int RecverHandler()
            {
                while (true)
                {
                    char *buffer = new char[EXPECT_SZ];
                    int sz = recv(fd_, buffer, EXPECT_SZ - 1, SOCK_NONBLOCK);
                    if (sz == EXPECT_SZ - 1)
                    {
                        recvbuffer.insert(recvbuffer.end(), buffer, buffer + sz);
                    }
                    else if (sz > 0)
                    {
                        std::cout << buffer << std::endl;
                        recvbuffer.insert(recvbuffer.end(), buffer, buffer + sz);
                        break;
                    }
                    else if (sz == 0)
                    {
                        return 1; // 如果 client 关闭连接 返回1 交给上层处理
                    }
                    else
                    {
                        if (errno & EAGAIN || errno & EWOULDBLOCK)
                        {
                            std::cout << strerror(errno) << std::endl;
                            ;
                            break;
                        }
                        else
                        {
                            std::abort();
                        }
                    }
                }
                return 0;
            }

            void SenderHandler()
            {

                while (true)
                {
                    int sz = send(fd_, sendbuffer.data(), 1500, SOCK_NONBLOCK);
                    if (sz == -1)
                    {
                        if (errno & EAGAIN || errno & EWOULDBLOCK)
                        {
                            _log(INFO, "发送缓冲区已满");
                            break;
                        }
                        else
                        {
                            std::abort();
                        }
                    }
                    else if (sz == 1500)
                    {
                        sendbuffer.erase(sendbuffer.begin(), sendbuffer.begin() + sz);
                    }
                    else if (sz > 0)
                    {
                        sendbuffer.erase(sendbuffer.begin(), sendbuffer.begin() + sz);
                        break;
                    }
                    else if (sz == 0)
                    {
                        _log(INFO, "发送完成");
                        break;
                    }
                }
            }

            void ExceptionHandler()
            {
            }

            std::string GetRecvbufferString()
            {
                return std::move(std::string(recvbuffer.begin(), recvbuffer.end()));
            }

            sht::LogMessage _log;                            // 日志信息
            sockaddr_in client_addr_;                        // 客户端地址
            int client_addr_len_;                            // 客户端地址长度
            int fd_;                                         // 文件描述符
            std::vector<char> recvbuffer;                    // 接收缓冲区
            std::vector<char> sendbuffer;                    // 发送缓冲区
            std::unordered_set<std::string> static_resource; // 静态资源
        };
#endif
    } // namespace sht
