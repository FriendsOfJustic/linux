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

void QueueInit(Queue* q);  //初始化队列

void QueuePush(Queue* q, Datatype x);  // 入队

void QueuePop(Queue* q);    // 出队

Datatype QueueFront(Queue* q);  //输出队列队头的元素

Datatype QueueBack(Queue* q); // 输出队列队尾的元素
  
int QueueSize(Queue* q);    //输出队列的大小

int QueueEmpty(Queue* q);   //判断队列是否为空

void QueueDestroy(Queue* q);   //队列销毁

