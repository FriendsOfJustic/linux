#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

void fun(int a = 0)
{
	cout << a << endl;
}
int mian()
{
	fun();
	fun(10);
	return 0;
}