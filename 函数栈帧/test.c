#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int add(int x, int y)
{
	return x+y;
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = add(a, b);
	return 0;

}