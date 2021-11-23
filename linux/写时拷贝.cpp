#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{
  string s("abcde");

  string s2(s);
  cout<<"修改之前："<<endl;
  printf("%p\n",s.c_str());
  printf("%p\n",s2.c_str());
  
  s2[3]='x';
  cout<<"修改之后: "<<endl;
  printf("%p\n",s.c_str());
  printf("%p\n",s2.c_str());
  return 0;
}
