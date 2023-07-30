//
// Created by 石海涛 on 2023-04-15.
//

#include "test.h"


#include <iostream

using  namespace std;

void fun(int& a=0)
{
    cout<<a<<endl;
}
int main()
{
    fun();
}