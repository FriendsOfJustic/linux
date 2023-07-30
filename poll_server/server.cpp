
#include"poll_server.hpp"
#include<memory>


using namespace std;

int main(){
    sht::LogMessage log;
    shared_ptr<sht::poll_server> p(new sht::poll_server(8080,log));
    p->init_server();
    p->run();
    return 0;

}