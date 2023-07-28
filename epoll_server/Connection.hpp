#include <iostream>
#include <string>
#include <arpa/inet.h>


namespace sht
{

    class Connection
    {
    public:
        void RecverHandler(){
        }

        void SenderHandler(){
        }

        void ExceptionHandler(){
        }
        sockaddr_in client_addr_; // 客户端地址
        int client_addr_len_;     // 客户端地址长度
        int fd_;                  // 文件描述符
        std::string recvbuffer;   // 接收缓冲区
        std::string sendbuffer;   // 发送缓冲区
    };
} // namespace sht
