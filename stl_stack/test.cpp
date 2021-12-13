#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"STL_stack.h"
using namespace std;


int main()
{
	sht::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;

}