#define _CRT_SECURE_NO_WARNINGS 1


#include"Date.h"


int main()
{
	Date d1(2021, 10, 14);
	Date d2(2021,1,1);

	//d1 += 100;



	//Date d2 = d1 + 100;

	cout << (d1 - d2) << endl;


	cout << (d1 < d2) << endl;



	return 0;



}