

#include"select_server.hpp"
#include<memory>

using namespace std;

int main(){

    sht::LogMessage log;
    shared_ptr<sht::select_server> p(new sht::select_server(8080,log));
    p->init_server();
    p->run();
    return 0;

}