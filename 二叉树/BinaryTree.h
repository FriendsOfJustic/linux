#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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

BT* BuyNode(int x);
BT* BinaryTreeCreate1(BT* root);
BT* BinaryTreeCreate2(BT* root);

//前序遍历
void PreOrder(BT* root);
//中序遍历
void InOrder(BT* root);
//后序遍历
void PostOrder(BT* root);

//二叉树节点个数
void BinaryTreeSize1(BT* root, int* x);

int BinaryTreeSize2(BT* root);

//二叉树叶子节点个数
int BinaryTreeLeafSize(BT* root);

//叶节点的个数
int BinaryTreeLevelKSize(BT* root, int k);

//树的高度
int BinaryTreeHeight(BT* root);

//二叉树查找值为x的节点
BT* BinaryTreeFind(BT* root, DataType x);