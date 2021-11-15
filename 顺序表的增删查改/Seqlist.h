#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SLDateType int

typedef struct SeqList
{
	SLDateType* arr;
	int sz;
	int capacity;
}SeqList;
 

void SeqListInit(SeqList* ps); //初始化顺序表
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);