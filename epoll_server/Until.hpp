#include<fcntl.h>
#include<string.h>
#include<iostream>


#ifndef UNTIL_HPP
#define UNTIL_HPP
void SetNoneBlock(int fd){
    int fl=fcntl(fd,F_GETFL);
    if(fl<0){
        strerror(errno);
        std::abort();
    }
    fcntl(fd,F_SETFL,fl|O_NONBLOCK);
}


#endif
