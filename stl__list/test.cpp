#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

int main()
{
	sht::list<int> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);


	auto be = p.begin();
	auto en = p.end();

	while (be != en)
	{
		std::cout << (*be) << " ";
		++be;
	}

	
}