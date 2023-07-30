#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

int main()
{
	SeqList p = { 0 };
	SeqList* ps = &p;
	SeqListInit(ps);
	/*SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 4);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 6);
	SeqListPushBack(ps, 7);*/

	/*SeqListPrint(ps);*/

	SeqListInsert(ps, 1, 100);
	SeqListPrint(ps);


	/*SeqListInsert(ps, 9, 100);
	SeqListPrint(ps);*/


	/*SeqListPopFront(ps);*/
	SeqListDestory(ps);
}