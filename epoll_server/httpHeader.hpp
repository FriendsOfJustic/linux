#include <functional>
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include"LogMessage.hpp"
#include<vector>

using namespace std;

// 解析Http请求 把Http请求解析成为三部分

#ifndef HTTP
#define HTTP
sht::LogMessage LOG;
namespace sht
{
    using namespace std;

    string default_home = "./rescource";

    //将http请求解析成一个KV对象！
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



    //将一个响应对象 转换成 http reponse 报文！！
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

        void setText(const vector<char> &buf)
        {
            third = string(buf.begin(), buf.end());
            KV["Content-Lenth"] = to_string(buf.size());
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

    vector<char> readFile(string filename)
    {
        LOG(INFO,"readfile_" + default_home + filename);
        int fd = open((default_home + filename).c_str(), O_RDONLY);
        if(fd<0){
            LOG(ERROR,"error static file");
           std::abort();
        }
        vector<char> buffer;
        struct stat filestat;
        fstat(fd,&filestat);
        char* readbuf=new char[filestat.st_size+1];
        LOG(INFO,std::to_string(filestat.st_blksize));
        int sz=read(fd,readbuf,filestat.st_blksize);
        LOG(INFO,std::to_string(sz));
        // //完美的循环读
        // while(true){
        //      char readbuf[filestat.st_blksize];
        //     int sz=read(fd,readbuf,filestat.st_blksize-1);
        //     LOG(INFO,std::to_string(sz)+"----------"+std::to_string(buffer.size()));
        //     if(sz>0){
        //        buffer.insert(buffer.end(),readbuf,readbuf+sz);
        //     }else if(sz==0){
        //         LOG(INFO,"here"+buffer.size());
        //         close(fd);
        //         break;
        //     }else{
        //         //异常
        //         close(fd);
        //         LOG(FATAL,"readfile读取错误");
        //         std::abort();
        //     }
        }
        
        //return buffer;
    }

    // int HtmlRequest(HttpRequest &req, HttpResponse &resp)
    // {
    //     // vector<char> buffer;
    //     // readFile(req.url,buffer);
    //     // resp.successHeader();
    //     // resp["Content-Type"] = "text/html";
    //     // resp.setText(buffer);
    // }

    int PngRequest(HttpRequest &req, HttpResponse &resp)
    {
        vector<char> buffer=readFile(req.url);
        LOG(INFO,"here"+buffer.size());
        resp.successHeader();
        resp["Content-Type"] = "application/x-png";
        resp.setText(buffer);
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
} // namespace sht

#endif
