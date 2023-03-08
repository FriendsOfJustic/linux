#define _CRT_SECURE_NO_WARNINGS 1


#include"BloomFilter.h"

#include<iostream>
#include<random>

#include<time.h>

using namespace std;


#define N 1000

int main()
{
	srand(time(0));
	string s = "i love you!";
	sht::BloomFilter<string, N> BF;

	for (int i = 0; i < N; i++)
	{
		s[rand() % s.size()]++;
		if (BF.test(s))
		{
			cout << "ÔÚ" << endl;
		}
		else
		{
			cout << "²»ÔÚ" << endl;
			BF.set(s);
		}
	}

}

