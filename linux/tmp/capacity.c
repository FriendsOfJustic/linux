#include<iostream>
#include<string>

using namespace std;
int main()        //验证g++增容倍数
{
  string s;
  size_t sz=s.capacity();
  for(int i=0;i<50;i++)
  {
    s.push_back('c');

    if(s.capacity() != sz)
    {
      sz=s.capacity();
      cout<<"new capacity :"<<sz<<endl;
    }


  }

  return 0;

}
