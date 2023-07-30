#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <stdio.h>

#ifndef LOGMESSAGE
#define LOGMESSAGE
enum type // 日志等级
{
    PRINT,
    NORMAL,
    WARNING,
    ERROR,
    FATAL
};

class LogMessage
{
public:
    LogMessage(const std::string &path)
        : _path(path)
    {
    }
    void operator()(std::string detail, type x)
    {
        time_t curtime;
        time(&curtime);
        std::string tmp(ctime(&curtime));
        tmp[tmp.size()] = '\0';
        std::string date = "[" + std::string(ctime(&curtime)) + "]";

        std::ofstream file;

        file.open(_path.c_str(), std::ios::app);
        std::string output;

        if (x == NORMAL)
        {
            output += "ERRO_RTYPE:NUORMAL: ";
        }
        else if (x == WARNING)
        {
            output += "ERRO_RTYPE:WARNING: ";
        }
        else if (x == ERROR)
        {
            output += "ERRO_RTYPE:ERROR: ";
        }
        else if (x == PRINT)
        {
            output += "RECCEIVE_MESSAGE: ";
        }
        else
        {
            output += "ERRO_RTYPE:FATAL: ";
        }

        if (x != PRINT)
            output += "  ERROR_DETAIL" + detail;
        else
            output += date + detail;
        // output[output.size()] = '\n';
        file << std::endl;
        std::cout << output;
        file.write(output.c_str(), output.size());
        file.close();
    }

    // void operator()(std::string detail, type x)
    // {

    //     FILE *file = fopen("/home/sht/test/计算机网络/Log/TCPLog.txt", "a+");
    //     std::string output;

    //     if (x == NORMAL)
    //     {
    //         output += "ERRO_RTYPE:NUORMAL";
    //     }
    //     else if (x == WARNING)
    //     {
    //         output += "ERRO_RTYPE:WARNING";
    //     }
    //     else if (x == ERROR)
    //     {
    //         output += "ERRO_RTYPE:ERROR";
    //     }
    //     else
    //     {
    //         output += "ERRO_RTYPE:FATAL";
    //     }

    //     output.push_back('\n');
    //     fwrite(output.c_str(), sizeof(char), output.size(), file);
    //     fclose(file);
    // }

private:
    std::string _path; // 设置日志的路径
};

#endif