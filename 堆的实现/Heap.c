#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"


void AdjustDown(int* a,int n,int parents)
{
	int child = 2 * parents + 1;
	while (child < n)
	{
		if (child+1<n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parents])
		{
			int temp = a[child];
			a[child] = a[parents];
			a[parents] = temp;
			parents = child;
			child = 2 * parents + 1;
		}
		else
		{
			break;
		}
	}

}
void AdjustUp(int* a, int n, int child)
{
	int parents = (child-1)/2;
	while (child > 0)
	{
		if (a[child] < a[parents])
		{
			int temp = a[child];
			a[child] = a[parents];
			a[parents] = temp;
			child = parents;
			parents = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void swap(int *a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void HeapCheck(Heap* p)
{
	if (p->sz == p->capacity)
	{
		p->a = (int*)realloc(p->a, p->capacity * 2 * sizeof(int));
		p->capacity *= 2;
	}
}
void HeapCreat(Heap** p)
{

	*p = (Heap*)malloc(sizeof(Heap));
	(*p)->a = (int*)malloc(4 * sizeof(int));
	(*p)->capacity = 4;
	(*p)->sz = 0;
}

void HeapDestroy(Heap* p)
{
	free(p->a);
	free(p);
	p = NULL;
}

void HeapPush(Heap* p, HPDataType x)
{
	HeapCheck(p);
	p->a[p->sz] = x;
	p->sz++;
	AdjustUp(p->a, p->sz, p->sz - 1);
	/*int child = p->sz-1;
	int parents = (child - 1) / 2;
	while (child > 0)
	{
		if (p->a[child] > p->a[parents])
		{
			swap(&p->a[child], &p->a[parents]);
			child = parents;
			parents = (child - 2) / 2;
		}
		else
		{
			break;
		}
	}*/
	/*for (int i = (p->sz - 2) / 2; i >= 0; i--)
	{
		int parents = i;
		int child = 2 * parents + 1;
		while (child < (p->sz - 2) / 2)
		{
			if (child+1< (p->sz - 2) / 2 && p->a[child] > p->a[child + 1])
			{
				child++;
			}
			if (p->a[parents] > p->a[child])
			{
				swap(&(p->a[parents]), &(p->a[child]));
				parents = child;
				child = 2 * parents + 1;
			}
			else
			{
				break;
			}
		}
	}*/


}

void HeapPop(Heap* p)
{
	swap(&p->a[p->sz - 1], &p->a[0]);
	AdjustDown(p->a, p->sz - 1, 0);
	/*int parents = 0;
	int child=2* parents + 1;
	while (child<p->sz-1)
	{
		if (child + 1 < p->sz-1 && p->a[child] < p->a[child + 1])
		{
			child++;
		}
		if (p->a[child] > p->a[parents])
		{
			swap(&p->a[child], &p->a[parents]);
			parents = child;
			child = 2 * parents + 1;
		}
		else
		{
			break;
		}
	}
	p->sz--;*/

}

HPDataType HeapTop(Heap* p)
{
	return p->a[0];
}

int HeapSize(Heap* p)
{
	return p->sz - 1;
}

int HeapEmpty(Heap* p)
{
	return p->sz == 0;
}

void HeapPrint(Heap* p)
{
	for (int i = 0; i < p->sz; i++)
	{
		printf(" %d ", p->a[i]);
	}
}



void PrintTopK(int* a, int n, int k)
{
	for (int i = (k-2)/2; i >=0; i--)
	{
		AdjustDown(a, k, i);
	}
	for (int i = k; i < n; i++)
	{
		if (a[i] > a[0])
		{
			int temp = a[i];
			a[i] = a[0];
			a[0] = temp;
			for (int i = (k - 2) / 2; i >= 0; i--)
			{
				AdjustDown(a, k, i);
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf(" %d ", a[i]);
	}
}