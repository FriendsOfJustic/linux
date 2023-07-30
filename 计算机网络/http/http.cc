#include "tcpserver.hpp"
#include "LogMessage.hpp"
#include <memory>
#include <unistd.h>
#include <fcntl.h>
#include "httpHeader.hpp"
#include "controller.hpp"
#include <dirent.h>
#include <vector>
#include "daemon.hpp"

using namespace std;

// 自动扫描 web目录下的所有文件名，并注册
vector<string> readResouceFile()
{
    vector<string> result;
    DIR *dir = opendir(default_home.c_str());
    if (dir == nullptr)
        return vector<string>();

    while (auto e = readdir(dir))
    {
        if (string(e->d_name) != "." && string(e->d_name) != "..")
            result.push_back("/" + string(e->d_name));
    }

    return move(result);
}
// port
int main(int argc, char **argv)
{
    HttepHandler controller;
    vector<string> filecontent = readResouceFile();
    for (auto e : filecontent)
    {
        if (e.find(".html"))
        {
            controller.Register(HtmlRequest, e);
        }
        if (e.find(".png"))
        {
            controller.Register(PngRequest, e);
        }
    }

    deamon();
    shared_ptr<sht::tcpserver> p = make_shared<sht::tcpserver>(atoi(argv[1]), "./log.txt", controller);
    p->init();
    p->run();
}