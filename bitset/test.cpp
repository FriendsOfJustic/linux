#define _CRT_SECURE_NO_WARNINGS 1



#include"bitset.h"

#include<iostream>

using namespace std;
#include<time.h>
#include<random>





int main()
{
	srand(time(0));
	sht::Bitset<1000> s;



	s.set(259);
	cout<<s.test(259);
	cout<<s.test(258);
}