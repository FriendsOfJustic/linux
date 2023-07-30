#include<unistd.h>
#include<string.h>
#include<string>
#include<ctime>


#ifndef LOG_EPOLLLOG
#define LOG_EPOLLLOG
namespace sht
{
    #ifndef STATUS
    #define STATUS
    enum Status{
        INFO ,
        DEBUG,
        WARNING,
        ERROR,
        FATAL
    };
    #endif
    class LogMessage{
        private:
        int fd;
        public:
        LogMessage(int _fd=1)
        :fd(_fd){
        }
        void operator()(enum Status status,std::string _msg){
            std::string _status;
            std::string pid=std::to_string(getpid());
            switch (status){
            case INFO:
                _status="[INFO]";
                break;
            case DEBUG:
                _status="[DEBUG]";
                break;
            case WARNING:
                _status="[WARNING]";
                break;
             case ERROR:
                _status="[ERROR]";
                break;
             case FATAL:
                _status="[FATAL]";
                break;
            default:
                write(fd,"日志参数出错",100);
                break;
            }
            time_t t;
            time(&t);
            std::string _time(ctime(&t));
            _time[_time.size()-1]='\0';
            std::string response="["+_time+"]  "+_status+"["+pid+"]  "+_msg;
            response.push_back('\n');
            write(fd,response.c_str(),response.size()+1);
            return ;
        }
    };
} // namespace sht

#endif
