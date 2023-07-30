#include<stdio.h>
#include<unistd.h>



int main()
{
  int g_val=1;

  int ret=fork();

  if(ret==0) //子进程
  {
    int count=5;
    while(count--)
    {
      printf("子进程：g_val == %d  &g_val==%p\n",g_val,&g_val);
      sleep(1);
    }
    g_val=2;

    while(1)
    {
      printf("子进程：g_val == %d  &g_val==%p\n",g_val,&g_val);
      sleep(1);
    }
  }else
  {
    
    while(1)
    {
      printf("父进程：g_val == %d  &g_val==%p\n",g_val,&g_val);
      sleep(1);
    }
  }
}
