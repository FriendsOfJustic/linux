#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#define SIZE 256
#define A 10


int main()
{
  char mycmd[SIZE];
  char * args[A];
  while(1)
  {
    printf("[tmp ^_^ @VM-16-7-centos ~]$ ");
    fgets(mycmd,SIZE,stdin);
    //printf("%s",mycmd);

    args[0]=strtok(mycmd," ");
    int i=1;
    while(args[i-1])
    {
      args[i++]=strtok(NULL," ");
    }
    args[i-2][strlen(args[i-2])-1]='\0';
    //if(args[i-1]==NULL)
    //  printf("hekko");
    //for(int j=0;j<i;j++)
    //{
    //  printf("%s\n",args[j]);
    //}
    int ret=fork();
    if(ret==0)
    {
      execvp(args[0],args);
      exit(0);
    }
    else
    {
      int status=0;
      int result=waitpid(-1,&status,0);
      if((status & 0x7f)==0)
      {
        printf("正常退出");
        printf("   退出码为：%d\n",status>>8);
      }else
      {
        printf("\n非正常退出！");
        printf("      错误信号是：%d\n",status & 0x7f);
      }

    }
  }
  return 0;
}

