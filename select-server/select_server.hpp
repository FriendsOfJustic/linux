#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include"LogMessage.hpp"
#include<cerrno>
#include<sys/select.h>
#include<list>
#include<algorithm>
namespace sht{
    #ifndef FDCOUNT
    #define FDCOUNT 1024
    #endif
    class select_server{

        private:
         //需要将 server关心的 读事件 的文件描述符 单独记录,下次select的时候重新设置
        void FDreset(fd_set& read_fd_set){
            FD_ZERO(&read_fd_set);
            max_readarray_fd=0;
            std::string curfd;
            for(auto& e:read_fd_array){
                FD_SET(e,&read_fd_set);
                max_readarray_fd=std::max(max_readarray_fd,e);
                curfd+=std::to_string(e);
            }
            _log(INFO,"fd array"+curfd);
        }
        public:
        explicit select_server(uint16_t port,const LogMessage& logmsg  ):_port(port),_log(logmsg){
        }
        void init_server(){
            sockfd=socket(AF_INET,SOCK_STREAM,0);
            std::cout<<sockfd<<std::endl;
            sockaddr_in server_addr;
            server_addr.sin_port=htons(_port);
            server_addr.sin_family=AF_INET;
            server_addr.sin_addr.s_addr=INADDR_ANY;

            int ret=bind(sockfd,(sockaddr*)&server_addr,sizeof server_addr);
            if(ret==-1){
                _log(FATAL,strerror(errno));
                std::abort();
            }else{
                _log(INFO,"bind success");
            }
        }
        void Recever(fd_set& read_fd_set,int fd){
            char *buffer=new char[4096];
            int sz=read(fd,buffer,sizeof buffer -1);
            if(sz>0){
                //_log(INFO,"read size:"+std::to_string(sz));
                buffer[sz]=0;
                _log(INFO,"client#: "+std::string(buffer)+"-----"+std::to_string(sz));
            }else if(sz==0){
                //客户端断开连接
                auto it=std::find(read_fd_array.begin(),read_fd_array.end(),fd);
                read_fd_array.erase(it);
                close(fd);
            }else{
                _log(ERROR,strerror(errno));
                std::abort();
            }
            
        }
        //
        void Accept(fd_set& read_fd_set){ 
            //走到这里可以直接accpet
            sockaddr_in client_addr;
            socklen_t sz=0;
            int confd=accept(sockfd,(sockaddr*)&client_addr,&sz);
            if(confd==-1){
                 _log(FATAL,strerror(errno));
                 std::abort();
            }
            max_readarray_fd=std::max((int)max_readarray_fd,confd);
            read_fd_array.push_back(confd);
        }

        void run(){
            int ret=listen(sockfd,20);
            if(ret<0){
                _log(DEBUG,strerror(errno));
                return ;
            }
            //设置listensock的套接字
            fd_set read_fd_set;
            FD_ZERO(&read_fd_set);
            FD_SET(sockfd,&read_fd_set);
            max_readarray_fd=sockfd;
            read_fd_array.push_back(sockfd);
            while(true){
                timeval time_break{1,0};
                FDreset(read_fd_set);
                //_log(INFO,"寻找连接,最大fd为:"+std::to_string(max_readarray_fd));
                int ret=select(max_readarray_fd+1,&read_fd_set,nullptr,nullptr,&time_break);   //非阻塞不等待
                if(ret>0){
                    if(FD_ISSET(sockfd,&read_fd_set)){
                        Accept(read_fd_set);
                        continue;;
                    }
                    for (int i = 0; i < FDCOUNT; i++){
                        if (FD_ISSET(i, &read_fd_set) && i!=sockfd){
                            //已连接的套接字发消息了!!!
                            Recever(read_fd_set,i);
                        }
                    }
                }else if(ret==-1){
                    //出现错误
                    _log(FATAL,strerror(errno));
                    std::abort();
                }else{
                    _log(ERROR,"读事件未就绪");
                }
            }
        }
        private:
        std::list<short> read_fd_array;
        short max_readarray_fd;    //读数组的最大 fd
        int count_readarry_count;   // 读fd数组的就绪文件描述符个数
        LogMessage _log;
        uint16_t _port;
        int sockfd;
    };
}