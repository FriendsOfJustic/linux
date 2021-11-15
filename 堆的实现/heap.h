#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int sz;
	int capacity;
}Heap;


void HeapCreat(Heap* p);

void HeapDestroy(Heap* p);

void HeapPush(Heap* p, HPDataType x);

void HeapPop(Heap* p);

HPDataType HeapTop(Heap* p);

int HeapSize(Heap* p);

int HeapEmpty(Heap* p);

void HeapPrint(Heap* p);

void TopK(int* a,int n,int k);