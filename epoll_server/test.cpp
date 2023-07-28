#include <pqxx/connection>

#include <iostream>

using namespace std;
int main()
{
    // 链接postgresql数据库  本地的5432端口  数据库名字为test    用户名为postgres  密码为123456
    time_t t;
    time(&t);
    std::string _time(ctime(&t));
    _time[_time.size()-1]='\0';
    cout<<ctime(&t);
    cout<<ctime(&t);

}