#define _CRT_SECURE_NO_WARNINGS 1


#include"BloomFilter.h"

#include<iostream>
#include<random>

#include<time.h>

using namespace std;




int main()
{
	string s = "i love you!ajkshdkajhduwhduiajsidhiouwhqouhdouhdoausfboasubcousbcouasdwuhoa";
	const size_t n = s.size() * 70;
	sht::BloomFilter<string, 76*70> BF;
	int f=0;
	int num = 0;
	for (int j = 0; j < s.size(); j++)
	{
		for (int i = 1; i < 70; i++)
		{
			s[j] += i;
			BF.test(s);

			if (BF.test(s) == false)
			{
				cout << "���ڡ����ж���ȷ" << endl;

			}
			else
			{
				cout << "�ڡ�������" << endl;
				f++;
			}
			num++;
		}

		


	}
	double x = (f * 1.0) / num;
	cout << "������Ϊ��" << x << endl;
}

