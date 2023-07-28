#include"EpollServer.hpp"
#include<memory>

using namespace std;

int main(int argc,char* argv[]){
    if(argc!=2){
        cout<<"param error"<<endl;
        std::abort();
    }
    shared_ptr<sht::epoll_server> ser(new sht::epoll_server(10,atoi(argv[1])));
    ser->Create();
    ser->Loop();
    
}