#include<stdio.h>
#include<unistd.h>
int main()
{
  fork();
  while(1)
  {
    printf("fuck you , bitch  pid: %u   ppid : %u \n",getpid(),getppid());
    sleep(1);
  }
  return 0;
}             
