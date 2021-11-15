#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//
//void fun1(struct SListNode** lists, int listsSize, struct SListNode** newhead, struct SListNode** cur)
//{
//    int min;
//    int k = 0;
//    for (int i = 0; i < listsSize; i++)
//    {
//        if (*(lists + i) != NULL)
//        {
//            min = (*(lists + i))->data;
//            k = i;
//            break;
//        }
//    }
//    for (int i = 0; i < listsSize; i++)
//    {
//        if (*(lists + i))
//        {
//            if ((*(lists + i))->data < min)
//            {
//                min = (*(lists + i))->data;
//                k = i;
//            }
//        }
//    }
//    if (*newhead == NULL)
//    {
//        *cur = *newhead = *(lists + k);
//        *(lists + k) = (*(lists + k))->next;
//        return;
//    }
//    (*cur)->next = *(lists + k);
//    *(lists + k) = (*(lists + k))->next;
//    *cur = (*cur)->next;
//}
//int fun2(struct SListNode** lists, int listsSize)
//{
//    for (int i = 0; i < listsSize; i++)
//    {
//        if (*(lists + i) != NULL)
//            return 1;
//    }
//    return 0;
//
//}
//struct SListNode* mergeKLists(struct SListNode** lists, int listsSize) {
//    
//    if (lists == NULL)
//        return NULL;
//    struct SListNode* newhead = NULL;
//    struct SListNode* cur = NULL;
//
//    while (fun2(lists, listsSize))
//    {
//        int min;
//        int k = 0;
//        for (int i = 0; i < listsSize; i++)
//        {
//            if (*(lists + i) != NULL)
//            {
//                min = (*(lists + i))->data;
//                k = i;
//                break;
//            }
//        }
//        for (int i = 0; i < listsSize; i++)
//        {
//            if (*(lists + i))
//            {
//                if ((*(lists + i))->data < min)
//                {
//                    min = (*(lists + i))->data;
//                    k = i;
//                }
//            }
//        }
//        if (newhead == NULL)
//        {
//            cur = newhead = *(lists + k);
//            *(lists + k) = (*(lists + k))->next;
//            continue;
//        }
//        (cur)->next = *(lists + k);
//        *(lists + k) = (*(lists + k))->next;
//        cur = (cur)->next;
//    }
//
//    if(cur)
//    cur->next = NULL;
//    return newhead;
//}

//
//SListNode* removeElements(SListNode* head, int val) {
//    if (head == NULL)
//        return NULL;
//    SListNode* newhead = NULL;
//    SListNode* cur = NULL;
//    while (head != NULL)
//    {
//        if (head->data != val)
//        {
//            if (newhead == NULL)
//            {
//                newhead = head;
//                cur = head;
//                cur = cur->next;
//                head = head->next;
//                continue;
//            }
//            cur = head;
//            head = head->next;
//            cur = cur->next;
//
//        }
//        else
//        {
//            head = head->next;
//        }
//    }
//    cur = NULL;
//    return newhead;
//
//}
SListNode* partition(SListNode* pHead, int x) {
    struct SListNode* n1 = NULL;
    struct SListNode* n2 = NULL;
    struct SListNode* cur1 = NULL;
    struct SListNode* cur2 = NULL;
    while (pHead)
    {
        if (pHead->data < x)
        {
            if (n1 == NULL)
            {
                n1 = cur1 = pHead;
                pHead = pHead->next;
                continue;
            }
            cur1->next = pHead;
            cur1 = cur1->next;
            pHead = pHead->next;
        }
        else
        {
            if (n2 == NULL)
            {
                n2 = cur2 = pHead;
                pHead = pHead->next;
                continue;
            }
            cur2->next = pHead;
            cur2 = cur2->next;
            pHead = pHead->next;
        }
    }
    if (n2)
        cur2->next = NULL;
    if (n1)
    {
        cur1->next = n2;
        return n1;
    }
    else
    {
        return n2;
    }
}
int main()
{
    /*SListNode* p1 = NULL;
    SListPushBack(&p1, 1);
    SListPushBack(&p1, 4);
    SListPushBack(&p1, 5);

    SListNode* p2 = NULL;
    SListPushBack(&p2, 1);
    SListPushBack(&p2, 3);
    SListPushBack(&p2, 4);

    SListNode* p3 = NULL;
    SListPushBack(&p3, 2);
    SListPushBack(&p3, 6);

    SListNode** p4 = NULL;
    struct SListNode* ps[3] = { p1,p2,p3 };
    
    SListPrint(mergeKLists(ps, 3));*/
    
    
    SListNode* p = NULL;
    SListPushBack(&p, 3);
    SListPushBack(&p, 3);
    SListPushBack(&p, 3);
    /*SListPushBack(&p, 3);
    SListPushBack(&p, 4);
    SListPushBack(&p, 5);*/
    SListPrint(partition(p, 3));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //SListNode* plist = NULL;
	////SListPopBack(&plist);
	//SListPushBack(&plist, 1);
	////SListPopBack(&plist);
	//SListPushBack(&plist, 2);
	//SListPushBack(&plist, 3);
	//SListPushBack(&plist, 4);
	//SListPushBack(&plist, 5);
	//SListPushBack(&plist, 6);
	//SListPushBack(&plist, 7);
	//SListPushFront(&plist, -1);

	///*SListPopBack(&plist);
	//SListPopBack(&plist);
	//SListPopFront(&plist);
	//SListPopFront(&plist);*/

	////printf("%d\n",SListFind(plist, 1)->data);
	//SListPrint(plist);
	//SListNode* insert = SListFind(plist, 1);
	//SListNode* Erase = SListFind(plist, 6);
	//SListInsertAfter(insert, 100);
	//SListPrint(plist);
	//SListEraseAfter(&Erase);
	//SListPrint(plist);
	//SListDestory(&plist);
}