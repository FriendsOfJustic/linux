#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include<stdbool.h>

void order(BT* ps)  //²ãÐò±éÀú
{
	Queue p;
	QueueInit(&p);
	if (ps != NULL)
	{
		QueuePush(&p, ps);

	}
	while (!QueueEmpty(&p))
	{
		BT* front = QueueFront(&p);
		QueuePop(&p);
		printf("%d", front->x);
		if (front->_left)
		{
			QueuePush(&p, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&p, front->_right);
		}
	}

	printf("\n");
	QueueDestroy(&p);
}

int BinaryTreeComplete(BT* ps)
{
	int ret = 1;
	Queue p;
	QueueInit(&p);
	if (ps != NULL)
	{
		QueuePush(&p, ps);

	}
	while (!QueueEmpty(&p))
	{
		BT* front = QueueFront(&p);
		QueuePop(&p);
		if (front == NULL)
			break;
		QueuePush(&p, front->_left);
		QueuePush(&p, front->_right);
	}
	while (!QueueEmpty(&p))
	{
		BT* front = QueueFront(&p);
		QueuePop(&p);
		if (front != NULL)
			return false;
	}
	QueueDestroy(&p);
	return true;
}
bool isSameTree(struct BinaryTree* leftTree, struct BinaryTree* rightTree)
{
	if (leftTree == NULL && rightTree == NULL)
		return true;

	if ((leftTree && rightTree) == 0)
		return false;

	if (leftTree->x != rightTree->x)
		return false;

	return isSameTree(leftTree->_left, rightTree->_left)
		&& isSameTree(leftTree->_right, rightTree->_right);
}

bool isSubtree(struct BinaryTree* root, struct BinaryTree* subRoot) {

	if (root == NULL)
		return false;

	if (isSameTree(root, subRoot))
		return true;

	return isSubtree(root->_left, subRoot) || isSubtree(root->_right, subRoot);



}



//
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//	if (root == NULL)
//		return NULL;
//	int** p = (int**)malloc(sizeof(int**));
//	Queue Q1;
//	QueueInit(&Q1);
//	QueuePush(&Q1, root);
//	int colsize = 1;
//	int size = 0;
//	int index = 1;
//	while (QueueEmpty(&Q1) != 0)
//	{
//		int m = 1;
//
//
//		for (int i = 0; i < index; i++)
//		{
//			if (QueueFront(&Q1))
//			{
//				p[colsize] = (int*)realloc(p[colsize], m);
//				(p[colsize])[m - 1] = QueueFront(&Q1)->val;
//				size++;
//				m++;
//				BT* temp = QueueFront(&Q1);
//				QueuePush(&Q1, temp->left);
//				QueuePush(&Q1, temp->left);
//			}
//
//			QueuePop(&Q1);
//		}
//		colsize++;
//		index *= 2;
//
//	}
//	QueueDestroy(&Q1);
//	*returnSize = size;
//	*returnColumnSizes = colsize;
//	return p;
//}
int main()
{
	BT* ps = NULL;
	ps=BinaryTreeCreate1(ps);
	BT* ret = BinaryTreeFind(ps,5);
	order(ps);
	/*BT* subroot = NULL;
	subroot=BinaryTreeCreate2(subroot);


	printf("%d",isSubtree(ps, subroot));*/

	/*PreOrder(ps);
	printf("\n");
	InOrder(ps);
	printf("\n");
	PostOrder(ps);
	int x = 0;
	BinaryTreeSize1(ps, &x);
	printf("\n%d\n", x);
	printf("%d\n", BinaryTreeSize2(ps));
	printf("%d\n", BinaryTreeLeafSize(ps));*/
	int a[10] = { 0 };
	int b = 1;
	int* c = &b;
	printf("%d", a[*c]);
}