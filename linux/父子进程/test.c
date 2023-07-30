#include<stdio.h>
#include<unistd.h>

int main()
{
  int a=fork();

  if(a==0)
  {
    while(1)
    {
      printf("i am son:   pid: %d  ppid:%d   \n",getpid(),getppid());
      sleep(1);
    }
  }
  else{

    while(1)
    {
      printf("i am father:   pid: %d  ppid:%d   \n",getpid(),getppid());
      sleep(1);
    }
  }
  return 0;
}
