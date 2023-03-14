#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
#include<iostream>


using namespace std;


int main()
{
	sht::vector<string> s{ "hello","bye" };

	for (auto e : s)
	{
		cout << e << endl;
	}
}