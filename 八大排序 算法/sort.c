#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"


void printArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void InsertSort(int* a, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[i + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = temp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n ;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n -gap; i++)
		{
			int end = i;
			int temp = a[i + gap];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = temp;
		}
	}
}


void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = end;
		for (int i = begin+1; i < end;i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}


		swap(&a[begin], &a[min]);

		if (begin != max)
			swap(&a[end], &a[max]);
		else
			swap(&a[end], &a[min]);

		begin++;
		end--;
	}
}


void AjustDown(int* a, int n, int parents)
{
	int child = 2 * parents + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parents])
			swap(&a[child], &a[parents]);
		parents = child;
		child = 2 * parents + 1;
	}
}


void HeapSort(int* a, int n)
{
	for (int i = n/2-1 ; i >= 0; i--)
	{
		AjustDown(a,n,i);
	}

	for (int i = n-1; i >0 ; i--)
	{
		swap(&a[0], &a[i]);
		AjustDown(a, i, 0);
	}
}


void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				k = 1;
			}
		}
		if (k == 0)
			break;
	}

}


int Choose_Key(int *a,int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])
			return left;
		else
		{
			if (a[right] > a[mid])
				return right;
			else
				return mid;
		}

	}
	else
	{
		if (a[mid] > a[right])
			return right;
		else
		{
			if (a[left] > a[mid])
				return left;
			else
				return mid;
		}

	}

}

//
int Partsort(int* a, int left,int right)  //但趟排序
{
	int key = left;
	int temp =Choose_Key(a,left,right);
	swap(&a[temp], &a[left]);
	while (left < right)
	{
		while (left<right && a[right] >= a[key])
			right--;

		while (left<right && a[left] <= a[key])
			left++;

		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
	return left;
}
//
//void QuickSort(int* a, int left,int right)
//{
//	int key = Quicksort(a,left,right);
//	if(key>left)
//	QuickSort(a, left, key - 1);
//	if(key<right)
//	QuickSort(a, key + 1, right);
//}



void QuickSort1(int* a, int n)     //hoare版本
{
	if (n == 1 || n == 0)
		return;
	int key = 0;
	int temp = Choose_Key(a, 0, n - 1);
	swap(&a[key], &a[temp]);
	int left = 0;   //这里必须从0开始，如果从1开始，当数组只有两个的时候代码会出现问题
	int right = n - 1;
	while (left < right)  //这里必须是小于号保证出循环left一定等于right
	{
		while (left<right && a[right] > a[key])
			right--;


		while (left<right && a[left] <= a[key])    //注意这里的大于等于号 因为key在左边，为了让key往左走必须大于等于
			left++;

		swap(&a[left], &a[right]);


	}
	swap(&a[left], &a[key]);
	key = left;

	QuickSort1(a, key);
	QuickSort1(a + key + 1, n - key - 1);

}



void QuickSort2(int* a, int n)          //快排——挖坑法
{
	if (n == 1 || n == 0)
		return;
	int key = 0;
	int t = Choose_Key(a, 0, n - 1);
	swap(&a[key], &a[t]);
	int left = 0; 
	int right = n - 1;
	int temp = a[key];
	while (left < right)
	{


		while (left<right && a[right]>temp)
			right--;
		a[left] = a[right];


		while (left<right && a[left]<= temp)
			left++;
		a[right] = a[left];



	}
	a[left] = temp;


	key = left;
	QuickSort2(a, key);
	QuickSort2(a + key + 1, n - key - 1);
	

}


void QuickSort3(int* a, int n)   //快排——双指针法
{
	if (n == 1 || n == 0)
		return;
	int key = 0;
	int temp = Choose_Key(a, 0, n - 1);
	swap(&a[key], &a[temp]);
	int prev = 0;
	int cur = 1;
	while (cur < n)
	{
		if (a[cur] < a[key])
			swap(&a[++prev], &a[cur]);
		cur++;
	}
	swap(&a[prev], &a[key]);

	key = prev;
	QuickSort3(a, key);
	QuickSort3(a + key + 1, n - key - 1);


}


void QuickSortNonR(int* a, int n)
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 0);        //入左区间
	StackPush(&ps, n - 1);     //入右区间

	while (!StackEmpty(&ps))
	{
		int end = StackTop(&ps);  //右区间先出栈
		StackPop(&ps);

		int begin = StackTop(&ps);  //左区间出栈
		StackPop(&ps);

		int keyi = Partsort(a, begin, end);
		if (keyi + 1 < end)
		{
			StackPush(&ps, keyi + 1);
			StackPush(&ps, end);
		}

		if (begin  < keyi-1)
		{
			StackPush(&ps, begin);
			StackPush(&ps, keyi - 1);
		}
	}
	StackDestroy(&ps);

}


int f(int *a,int n)
{
	int key = 0;
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while (left<right && a[right]>a[key])
			right--;
		while (left < right && a[left] <= a[key])
			left++;
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[key]);
	return left;
}
void quicksortNonR(int* a, int n)
{
	Stack p;
	StackInit(&p);
	StackPush(&p, 0);
	StackPush(&p, n - 1);
	while (!StackEmpty(&p))
	{
		int right = StackTop(&p);
		StackPop(&p);

		int left = StackTop(&p);
		StackPop(&p);

		if (right >= left + 1)
		{
			int key = f(a + left, right - left+1);
			key = key + left;


			StackPush(&p, left);
			StackPush(&p, key - 1);

			StackPush(&p, key + 1);
			StackPush(&p, right);
		}
	}
}









void _MergeSort(int* a, int left,int right,int *temp)
{
	int mid = (left + right) / 2;
	if (left >= right)
		return;
	_MergeSort(a, left, mid,temp);
	_MergeSort(a, mid + 1, right,temp);

	int cur1 = left, end1 = mid;
	int cur2 = mid + 1, end2 = right;
	int cur3 = left;

	while (cur1 <= end1 && cur2 <= end2)
	{
		if (a[cur1] <= a[cur2])
		{
			temp[cur3] = a[cur1];
			cur3++;
			cur1++;
		}
		else
		{
			temp[cur3] = a[cur2];
			cur3++;
			cur2++;
		}
	}
	while (cur1 <= end1)
	{
		temp[cur3] = a[cur1];
		cur3++;
		cur1++;
	}
	while (cur2 <= end2)
	{
		temp[cur3] = a[cur2];
		cur3++;
		cur2++;
	}
	for (int i = 0; i <= right; i++)
	{
		a[i] = temp[i];
	}

}

void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(n * sizeof(int));
	_MergeSort(a, 0, n - 1, temp);
}


void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* p = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		p[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (p[i])
		{
			a[j++] = i + min;
			p[i]--;
		}
	}
}



void fun(int cur1,int end1,int cur2,int end2,int cur3,int *temp,int *a)
{
	while (cur1 <= end1 && cur2 <= end2)
	{
		if (a[cur1] <= a[cur2])
		{
			temp[cur3] = a[cur1];
			cur3++;
			cur1++;
		}
		else
		{
			temp[cur3] = a[cur2];
			cur3++;
			cur2++;
		}
	}
	while (cur1 <= end1)
	{
		temp[cur3] = a[cur1];
		cur3++;
		cur1++;
	}
	while (cur2 <= end2)
	{
		temp[cur3] = a[cur2];
		cur3++;
		cur2++;
	}
	for (int i = 0; i <= end2; i++)
	{
		a[i] = temp[i];
	}
}
void MergeSortNonR(int* a, int n)
{
	int* p = (int*)malloc(n * sizeof(int));
	int index = 2;
	while ((n*2) / index)
	{
		int times = n / index;
		if (n % index != 0)
			times++;
		for (int i = 0; i < times; i++)
		{
			int cur1 = i * index, end1 = cur1+ index/2 -1;
			if (end1 > n - 1)
				end1 = n - 1;
			int cur2 = cur1 + index / 2;
			int	end2 = cur2 + index/2 - 1;
			if (end2 > n - 1)
				end2 = n - 1;
			int cur3 = cur1;
			fun(cur1, end1, cur2, end2, cur3, p, a);

		}
		index *= 2;

	}
	free(p);
}
