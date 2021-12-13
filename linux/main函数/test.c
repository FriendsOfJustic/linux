#include<stdio.h>
#include<string.h>

int main(char argc,char* argv[])//探究main函数的参数的意义
{
  if(argc == 0)
    return 0;

  if(argc!=0)
  {
    for(int i=0;argv[i];i++)
    {
      if(strcmp("-a",argv[i])==0)
      {
        printf("hello world!\n");
      }
      else if(strcmp("-b",argv[i]) == 0)
      {
        printf("hello linux\n");
      }

    }
  }
  return 0;

}
