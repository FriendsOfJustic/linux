#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"vector.h"

int main()
{
	sht::vector<int> v;
	//v.reserve(20);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	
	auto a = v.begin();
	v.insert(a, 10);

	v.erase(a + 1);

	v.print();

	/*while (a != b)
	{
		std::cout << *a << " ";
		a++;
	}*/

	/*sht::vector<int> copy(a, b);*/


	/*sht::vector<int> b;
	b = v;
	b.print();*/


}