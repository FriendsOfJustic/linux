#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class User
{
public:
    User(std::string ip, std::string port)
        : _ip(ip), _port(port)
    {
    }
    std::string _ip;
    std::string _port;
};

class User_management
{
public:
    void add_user(sockaddr_in client)
    {
        std::string port = to_string(ntohs(client.sin_port));
        std::string ip = inet_ntoa(client.sin_addr);
        usermap.insert(make_pair(port + " : " + ip, client));
        cout << "添加用户成功" << endl;
    }

    void delete_user(sockaddr_in client)
    {
        std::string port = to_string(ntohs(client.sin_port));
        std::string ip = inet_ntoa(client.sin_addr);
        usermap.erase(port + " : " + ip);
        cout << "删除用户成功" << endl;
    }

    bool is_user(sockaddr_in client)
    {
        std::string port = to_string(ntohs(client.sin_port));
        std::string ip = inet_ntoa(client.sin_addr);
        return usermap.find(port + " : " + ip) != usermap.end();
    }
    std::unordered_map<std::string, sockaddr_in> usermap;
};