#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"




int main()
{
	int a[] = { -4,0,7,4,9,-5,-1,0,-7,-1};
	int sz = sizeof(a) / sizeof(int);

	/*InsertSort(a, sz);
	printArry(a, sz);

	ShellSort(a, sz);
	printArry(a, sz);

	SelectSort(a, sz);
	printArry(a, sz);

	HeapSort(a, sz);
	printArry(a, sz);

	BubbleSort(a, sz);
	printArry(a, sz);

	QuickSort2(a, sz);
	printArry(a, sz);

	MergeSort(a, sz);
	printArry(a, sz);

	CountSort(a, sz);
	printArry(a, sz);

	MergeSortNonR(a, sz);
	printArry(a, sz);*/


	quicksortNonR(a, sz);
	printArry(a, sz);

}