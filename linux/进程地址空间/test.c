#include<stdio.h>
#include<stdlib.h>
int val2;
int val1=2;
int main(int argc,char *argv[],char *env[])
{
  printf("代码段：%p\n",main);
  const char *p="hello world";
  printf("常量区：%p\n",p);
  printf("已初始化全局变量：%p\n",&val1);

  printf("未初始化全局变量：%p\n",&val2);

  int *t=(int *)malloc(4);

  printf("堆：%p\n",t);
  printf("栈：%p\n",&t);

  printf("命令行参数：%p\n",argv[0]);

  printf("环境变量：%p\n",env[0]);

}
