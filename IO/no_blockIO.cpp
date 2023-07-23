#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<cerrno>
#include<sys/select.h>
#include<vector>
using namespace std;



// int main()
// {
//     int f1=fcntl(0,F_GETFL);

//     fcntl(0,F_SETFL,f1|O_NONBLOCK);


//     while(1)
//     {
//         char buffer[1024];
//        int ret=read(0,buffer,1024);
//        if(ret>0){
//         buffer[ret]='\n';
//         cout<<"我读取到内容  "<<buffer<<endl;
//        }
//        else if(ret==-1){
//         cout<<"读取错误"<<endl;
//         perror("read fail");
//        }
//        else
//        {
//         cout<<"我没有被阻塞"<<endl;
//        }
//         sleep(2);

//     }
// }




int main()
{
    int f1=fcntl(0,F_GETFL);

    fcntl(0,F_SETFL,f1|O_NONBLOCK);


    while(1)
    {
        char buffer[1024];
       int ret=recv(0,buffer,1024,SOCK_NONBLOCK);
       if(ret>0){
        buffer[ret]='\0';
        cout<<"我读取到内容  "<<buffer<<endl;
       }
       else if(ret==-1){
        cout<<"读取错误"<<endl;
        perror("read fail");
       }
       else
       {
        cout<<"我没有被阻塞"<<endl;
       }
        sleep(2);

    }
}