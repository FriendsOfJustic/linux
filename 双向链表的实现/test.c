#define _CRT_SECURE_NO_WARNINGS 1
#include"DoubleList.h"

int main()
{
	Dlist* plist = NULL;
	IniteDlist(&plist);
	DListPushBack(plist,1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPushBack(plist, 5);
	DListPushBack(plist, 6);
	DListPushBack(plist, 7);
	ListPrint(plist);

	DListPushFront(plist, -1);
	ListPrint(plist);

	DListPopBack(plist);
	ListPrint(plist);

	DListPopFront(plist);
	ListPrint(plist);

	Dlist* p = Listfind(plist, 6);
	DlistErease(p);
	ListPrint(plist);

	Dlist* ps = Listfind(plist, 3);
	DlistInsert(ps, 1000);
	ListPrint(plist);


}