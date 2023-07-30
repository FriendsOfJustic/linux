#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>



typedef int DataType;
typedef struct BinaryTree
{
	DataType x;
	struct BinaryTree* _left;
	struct BinaryTree* _right;
}BT;


typedef BT* Datatype;
typedef struct listNode
{
	Datatype x;
	struct listNode* next;
}ListNode;

typedef struct Queue
{
	ListNode* head;
	ListNode* tail;
}Queue;

void QueueInit(Queue* q);  //��ʼ������

void QueuePush(Queue* q, Datatype x);  // ���

void QueuePop(Queue* q);    // ����

Datatype QueueFront(Queue* q);  //������ж�ͷ��Ԫ��

Datatype QueueBack(Queue* q); // ������ж�β��Ԫ��
  
int QueueSize(Queue* q);    //������еĴ�С

int QueueEmpty(Queue* q);   //�ж϶����Ƿ�Ϊ��

void QueueDestroy(Queue* q);   //��������

