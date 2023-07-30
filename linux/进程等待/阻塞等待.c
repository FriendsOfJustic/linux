#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
  int ret=fork();

  if(ret==0)
  {
    int count=5;
    while(count--)
    {
      printf("i am son!\n");
      sleep(1);
    }
    int a=1/0;
    exit(0);
  }
  int status=0;
  waitpid(ret,&status,0);
  printf("i am father\n");
  if((status & 0x7f) == 0 ) //进程正常退出 下面判断退出码来判断结果是否正确！
  {
    printf("进程正常退出！\n");
    printf("退出码是：%d\n",(status>>8) & 0xff);
  }
  else   // 进程异常退出  
  {
    printf("进程异常退出!\n");
    printf("中断信号是：%d\n",status & 0x7f);
  }
  return 0;
}
