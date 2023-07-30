#define _CRT_SECURE_NO_WARNINGS 1



#include"set.h"
#include<iostream>

using namespace std;


int main()
{
	sht::set<int> s;
	vector<int> v = { 1,2,1,3,1,4,1,5,5,2,3,4,5 };

	for (auto e : v)
	{
		s.insert(e);
	}

	s.BFS();

}