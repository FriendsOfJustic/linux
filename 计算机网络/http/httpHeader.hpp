
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

// 解析Http请求 把Http请求解析成为三部分

#ifndef HTTP
#define HTTP

string default_home = "./rescource";
class HttpRequest
{
public:
    HttpRequest(string r)
        : Request(r)
    {
    }

    // 解析http请求
    bool Prase()
    {
        stringstream ss(Request);
        string header;
        getline(ss, header, '\n');
        // 把URL切出来
        stringstream s2(header);
        getline(s2, method, ' ');
        getline(s2, url, ' ');
        getline(s2, version, ' ');

        // cout << method << "&&" << url << endl;

        string cur;
        while (getline(ss, cur, '\n'))
        {
            if (cur.size() != 0)
            {
                int pos = cur.find(": ");
                string key = cur.substr(0, pos);
                string value = cur.substr(pos + 2);
                KV[key] = value;
            }
            else
                break;
        }
        getline(ss, Text, '\n');

        return true;
    }
    string Request;
    string method;
    string url;
    string version;
    unordered_map<string, string> KV;
    string Text;
};

class HttpResponse
{
public:
    HttpResponse()
    {
    }

    void successHeader()
    {
        first += "HTTP/1.1 200 success\n";
    }

    void failHeader()
    {
        first += "HTTP/1.1 200 fail\n";
    }

    string &operator[](string key)
    {
        return KV[key];
    }

    void setText(char *p, int sz)
    {
        third += "\n";
        for (int i = 0; i < sz; i++)
        {
            third.push_back(p[i]);
        }
        KV["Content-Lenth"] = to_string(sz);
        KV["Set-Cookie"] = "fuck-you-bitch";
    }

    string generator()
    {
        for (auto e : KV)
        {
            second += e.first + ": " + e.second + "\n";
        }
        return move(first + second + third);
    }

private:
    string first;
    string second;
    string third;
    unordered_map<string, string> KV;
};

int readFile(string filename, char *buffer, int sz = INT32_MAX)
{
    // cout << "readfile_" << default_home + filename << endl;
    int fd = open((default_home + filename).c_str(), O_RDONLY);
    int read_sz = read(fd, buffer, sz);
    return read_sz; // 返回读取文件字节数
}

int HtmlRequest(HttpRequest &req, HttpResponse &resp)
{
    char buffer[1024 * 1024 * 5];
    int sz = readFile(req.url, buffer, 1024 * 1024 * 5);
    resp.successHeader();
    resp["Content-Type"] = "text/html";
    resp.setText(buffer, sz);
}

int PngRequest(HttpRequest &req, HttpResponse &resp)
{
    char buffer[1024 * 1024];
    int _sz = readFile(req.url, buffer);
    resp.successHeader();
    resp["Content-Type"] = "application/x-png";
    resp["Content-Lenth"] = to_string(_sz);
    resp.setText(buffer, _sz);
}

class HttepHandler
{
    typedef function<int(HttpRequest &, HttpResponse &)> controller;

public:
    HttepHandler()
    {
        // 首先自己注册404方法
        map["/notfound.html"] = HtmlRequest;
    }
    bool Register(controller con, string index)
    {
        if (map.find(index) == map.end())
            map[index] = con;
        else
            return false;

        return true;
    }
    unordered_map<string, controller> map;
};

#endif