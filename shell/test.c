#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>


#define SIZE 256
#define A 10

void redirect(int ret,char* d)
{
  int i=0;
  while(d[i+1]!='\0')
    i++;
  d[i]='\0';
  int fd;
  if(ret==1)
    fd=open(d,O_CREAT | O_WRONLY,0700);
  if(ret==2)
    fd=open(d,O_CREAT | O_WRONLY | O_APPEND,0700);

  dup2(fd,1);

}


int judg(char *p,char ** d)
{
  int ret=0;
  int i=0;
  while(p[i]!='\0')
  {
    if(p[i]=='>')
    {
      ret=1;
      p[i]='\0';
      if(p[i+1]=='>')
      {
        i++;
        ret=2;
      }
      break;
    }
    i++;
  }
  while(p[++i]==' ');
  *d=p+i;
  return ret;
}




int main()
{
  char mycmd[SIZE];
  char mycmd2[SIZE];
  char * args[A];
  while(1)
  {
    printf("[tmp ^_^ @VM-16-7-centos ~]$ ");
    fgets(mycmd,SIZE,stdin);
    //printf("%s",mycmd);
    char *d=NULL;
    int jud=0;
    jud=judg(mycmd,&d);
    //printf(d);
    //printf(mycmd);
    strcpy(mycmd2,mycmd);
    //printf(mycmd2);

    args[0]=strtok(mycmd2," ");
    int i=1;
    while(args[i-1])
    {
      args[i++]=strtok(NULL," ");
    }
    if(jud==0)       //你麻痹这个地方的错误我找了一个多小时 艹
    args[i-2][strlen(args[i-2])-1]='\0';
    //if(args[i-1]==NULL)
    //  printf("hekko");
    //for(int j=0;j<i-1;j++)
    //{
      //printf("%s\n",args[j]);
    //}
    int ret=fork();
    if(ret==0)
    {
      //printf(d);
      if(jud)
        redirect(jud,d);
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

