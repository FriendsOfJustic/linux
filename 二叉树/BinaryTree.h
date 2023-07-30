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

//ǰ�����
void PreOrder(BT* root);
//�������
void InOrder(BT* root);
//�������
void PostOrder(BT* root);

//�������ڵ����
void BinaryTreeSize1(BT* root, int* x);

int BinaryTreeSize2(BT* root);

//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BT* root);

//Ҷ�ڵ�ĸ���
int BinaryTreeLevelKSize(BT* root, int k);

//���ĸ߶�
int BinaryTreeHeight(BT* root);

//����������ֵΪx�Ľڵ�
BT* BinaryTreeFind(BT* root, DataType x);