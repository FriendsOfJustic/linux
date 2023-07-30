#include <iostream>
#include <string>
#include <arpa/inet.h>


namespace sht
{

    #ifndef EPOLL_CONN
    #define EPOLL_CONN
    const int EXPECT_SZ=3;
    class Connection
    {
    public:
        int RecverHandler(){
            while(true){
                char * buffer=new char[EXPECT_SZ];
                int sz=recv(fd_,buffer,EXPECT_SZ-1,SOCK_NONBLOCK);
                if(sz==EXPECT_SZ-1){
                    buffer[sz]=0;
                    recvbuffer.append(buffer);
                }else if(sz>0 ){
                    buffer[sz]=0;
                    std::cout<<buffer<<std::endl;
                    recvbuffer.append(buffer);
                    break;
                }else if(sz==0){
                    return 1;     //如果 client 关闭连接 返回1 交给上层处理               
                }else{
                    if(errno & EAGAIN  || errno & EWOULDBLOCK){
                        std::cout<<strerror(errno)<<std::endl;;
                        break;
                    }else{
                        std::abort();
                    }
                }
            }
            return 0;
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
    #endif
} // namespace sht

