#include<iostream>
#include<unistd.h>
#include<fcntl.h>


using namespace  std;


int main()
{
  int fd =open("./log.txt",O_RDWR|O_CREAT|O_APPEND);

  if(fork())
  {
    while(1)
    {

    
      char Buffer[]="hello world";
      write(fd,Buffer,sizeof Buffer);
    }
  } 
  else 
  {
    while(1)
    {

    
    char Buffer[]="hello world";
    write(fd,Buffer,sizeof Buffer);


  }
  }


  
  return 0;
}



