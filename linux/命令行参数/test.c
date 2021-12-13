#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
 // for(int i=0;argv[i];i++)
 //   printf("%s\n",argv[i]);
 // printf("%d",argc);
  if(argc > 1)
  {
    for(int i=1;i<argc;i++)
    {
      if(strcmp(argv[i],"-a")==0)
        printf("执行a选项\n");
      else if(strcmp(argv[i],"-b")==0)
        printf("执行-b选项\n");
    }
  }
  else
  {
    printf("没有命令行参数\n");
  }

}
