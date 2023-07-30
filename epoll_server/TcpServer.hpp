#include <sys/socket.h>
#include <arpa/inet.h>
#include "LogMessage.hpp"
#include "Until.hpp"
#include "Connection.hpp"
#include <unordered_map>


namespace sht
{
    class TcpServer
    {
    public:
        void Sock(uint16_t port)
        {
            fd_ = socket(AF_INET, SOCK_STREAM, 0);
            if (fd_ < 0)
            {
                log_(FATAL, "socket error");
                std::abort();
            }
            SetNoneBlock(fd_); // 把接受连接的文件描述符设置为非阻塞
            sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port);
            server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
            int ret = bind(fd_, (struct sockaddr *)&server_addr, sizeof(server_addr));
            if (ret < 0)
            {
                log_(FATAL, "bind error");
                std::abort();
            }
        }

        int Accept(sht::Connection * conn)
        {
            sockaddr_in client_addr;
            int client_addr_len;
            int fd = accept(fd_, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
            if (fd < 0)
            {
                if (errno & EAGAIN || errno & EWOULDBLOCK)
                {
                    log_(INFO, "no more accpet");
                    return -1;
                }
                else
                {
                    log_(FATAL, "accpet unkown error");
                    delete conn;
                    std::abort();
                }
            }
            else if (fd > 0)
            {
                 log_(INFO, "receive a connect "+std::to_string(fd));
                conn->client_addr_ = client_addr;
                conn->client_addr_len_ = client_addr_len;
                conn->fd_ = fd;
                return fd;
            }
        }

        void Listen()
        {
            int ret = listen(fd_, 5);
            if (ret < 0)
            {
                log_(FATAL, "listen error");
                std::abort();
            }
        }

        // 返回文件描述符
        int FD()
        {
            return fd_;
        }

        ~TcpServer(){
            
            close(fd_);
        }

    private:
        int fd_=0; // 文件描述符
        LogMessage log_;
    };
} // namespace sht
