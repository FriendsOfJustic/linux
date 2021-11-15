#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"


int main()
{

	//Heap* ps = NULL;
	//HeapCreat(&ps);
	//HeapPush(ps, 15);
	//HeapPush(ps, 20);
	//HeapPush(ps, 13);
	//HeapPush(ps, 17);
	//HeapPush(ps, 12);
	//HeapPush(ps, 14);
	///*HeapPush(ps, 16);
	//HeapPush(ps, 1);
	//HeapPush(ps, 50);*/
	//HeapPop(ps);
	//HeapPrint(ps);
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 100000 + 1;
	a[1231] = 100000 + 2;
	a[531] = 100000 + 3;
	a[5121] = 100000 + 4;
	a[115] = 100000 + 5;
	a[2335] = 100000 + 6;
	a[9999] = 100000 + 7;
	a[76] = 100000 + 8;
	a[423] = 100000 + 9;
	a[3144] = 100000 + 10;
	PrintTopK(a, 10000, 10);

}