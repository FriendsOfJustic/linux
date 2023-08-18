
#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<vector>
#include<sys/stat.h>

using namespace std;
int readFile(string filename,vector<char>& buffer)
{
        int fd = open("../rescource/197122f81969786c3e8aee62d26b3d1.png", O_RDONLY);
        if(fd<0){
            cout<<"fail"<<endl;
            return -1;
        }
        struct stat filestat;
        fstat(fd,&filestat);
        //完美的循环读
        while(true){
            char readbuf[filestat.st_blksize];
            int sz=read(fd,readbuf,filestat.st_blksize-1);

           if(sz>0){
               buffer.insert(buffer.end(),readbuf,readbuf+sz);
            }else if(sz==0){
                close(fd);
                break;
            }else{
                //异常
                close(fd);
                cout<<strerror(errno);
                return -1;
            }
        }
        return 0;
 }

 int main(){
    vector<char> buffer;
    readFile("../rescource/t.txt",buffer);
    cout<<buffer.size()<<endl;
    // for(auto e:buffer){
    //     cout<<e;
    // }

    return 0;
 }
