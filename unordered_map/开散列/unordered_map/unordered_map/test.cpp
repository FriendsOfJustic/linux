#define _CRT_SECURE_NO_WARNINGS 1
#include"unordered_map.h"
#include<iostream>

using namespace std;


int main()
{
	sht::unordered_map<int, int> m;
	vector<int> s1 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> s2 = { 1,11,21,31,41,51,61,71,81,91,101,111 };
	for (auto& e : s2)
	{
		m.insert(make_pair(e, 0));
	}

	m.insert(make_pair(11, 0));


	auto it=m.find(11);


}