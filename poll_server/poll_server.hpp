#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include"LogMessage.hpp"
#include<cerrno>
#include<poll.h>
#include<list>
#include<algorithm>
#include<libpq-fe.h>


namespace sht{
    #ifndef FDCOUNT
    #define FDCOUNT 1024
    #endif
    class poll_server{
        private:
         //需要将 server关心的 读事件 的文件描述符 单独记录,下次select的时候重新设置
        public:
        explicit poll_server(uint16_t port,const LogMessage& logmsg):_port(port),_log(logmsg),fd_list(new pollfd[FDCOUNT]){
            for(int i=0;i<FDCOUNT;i++){
                fd_list[i].fd=-1;
                fd_list[i].events=0;
            }
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
        void Recever(int pos){
            _log(INFO,"read in");
            int curfd=fd_list[pos].fd;

            char *buffer=new char[1024];

            int sz=read(curfd,buffer,1024);
            _log(INFO,"收到字节:"+std::to_string(sz));
            if(sz>0){
                buffer[strlen(buffer)]='\0';
                 _log(INFO,"打印字节:"+std::to_string(strlen(buffer)));
                _log(INFO,"client  # "+std::string(buffer));
            }else if(sz==0){
                _log(INFO,"client close connection");
                sleep(5);
                fd_list[pos].fd=-1;
                fd_list[pos].events=0;
                fd_list[pos].revents=0;
                close(curfd); 
            }else {
                _log(ERROR,"read error");
            }
        }
        //
        void Accept(int pos){ 
            //走到这里可以直接accpet
            sockaddr_in client_addr;
            socklen_t sz=0;
            int confd=accept(sockfd,(sockaddr*)&client_addr,&sz);
            fd_list[confd].fd=confd;
            fd_list[confd].events=POLLIN;
            if(confd==-1){
                 _log(FATAL,strerror(errno));
                 std::abort();
            }
            else
            _log(INFO,"accept success! ");
        }

        //处理读事件
        void readEventHandler(int pos){
            if(fd_list[pos].fd==sockfd){
                Accept(pos);
            }else{
                Recever(pos);
            }
        }
        void run(){
            int ret=listen(sockfd,20);
            if(ret<0){
                _log(DEBUG,strerror(errno));
                return ;
            }
            _log(DEBUG,"listen success");
            fd_list[sockfd].fd=sockfd;
            fd_list[sockfd].events=POLLIN;
            //设置listensock的套接字
            while(true){
                _log(INFO,"polling");
                int ret=poll(fd_list,FDCOUNT,200);
                if(ret>0){
                    //代表有事件就绪了
                    for(int i=0;i<FDCOUNT;i++){
                        if(fd_list[i].revents==POLLIN){
                            //有读事件就绪
                            readEventHandler(i);
                        }else if(fd_list[i].revents ==POLLOUT){
                            //有写事件就绪
                            //TODO
                        }
                    }
                }else if(ret<0){
                    _log(ERROR,"POLL ERROR");
                    std::abort();
                }
            }
        }
        private:
        pollfd * fd_list;   //pollfd 数组
        LogMessage _log;
        uint16_t _port;
        int sockfd;
    };
}