#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

BT* BuyNode(int x)
{
	BT*root = (BT*)malloc(sizeof(BT));
	root->x = x;
	root->_left = root->_right = NULL;
	return root;
}

BT* BinaryTreeCreate1(BT* root)
{
	BT* n1 = BuyNode(3);
	BT* n2 = BuyNode(5);
	BT* n3 = BuyNode(4);
	BT* n4 = BuyNode(1);
	BT* n5 = BuyNode(2);
	BT* n6 = BuyNode(0);


	n1->_left = n3;
	n1->_right = n2;
	n3->_left = n4;
	n3->_right = n5;
	n5->_left = n6;

	return n1;
}
BT* BinaryTreeCreate2(BT* root)
{
	BT* n1 = BuyNode(4);
	BT* n2 = BuyNode(2);
	BT* n3 = BuyNode(1);
	

	n1->_left = n3;
	n1->_right = n2;

	return n1;
}


void PreOrder(BT* root)
{
	if (root == NULL)
	{
		printf(" NULL->");
		return;
	}
	else
		printf("%c->", root->x);
	PreOrder(root->_left);
	PreOrder(root->_right);

}
void InOrder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL->");
		return;
	}
	else
	{
		InOrder(root->_left);
	}
	printf("%c->", root->x);
	InOrder(root->_right);
}

void PostOrder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL->");
		return;
	}
	else
	{
		PostOrder(root->_left);
	}
	PostOrder(root->_right);
	printf("%c->", root->x);
}

//二叉树节点个数
void BinaryTreeSize1(BT* root, int* x)
{
	if (root == NULL)
		return;
	else
		*x+=1;
	BinaryTreeSize1(root->_left, x);
	BinaryTreeSize1(root->_right, x);
}
int BinaryTreeSize2(BT* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize2(root->_left) + BinaryTreeSize2(root->_right) + 1;

}
//二叉树叶子节点个数
int BinaryTreeLeafSize(BT* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right==NULL)
		return 1;
	/*if(root->_left)
	BinaryTreeLeafSize(root->_left);
	if(root->_right)
	BinaryTreeLeafSize(root->_right);*/
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	
}
//二叉树第K层节点个数
int BinaryTreeLevelKSize(BT* root, int k)
{
	if (root == NULL)
		return 0;
	else
	{
		if (k == 1)
			return 1;
		else
			return  BinaryTreeLevelKSize(root->_left, k-1) + BinaryTreeLevelKSize(root->_right, k-1);
	}
}
//二叉树的深度
int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int BinaryTreeHeight(BT* root)
{
	if (root == NULL)
		return 0;

	return Max(BinaryTreeHeight(root->_left), BinaryTreeHeight(root->_right)) + 1;

}

//二叉树查找值为x的节点
BT* BinaryTreeFind(BT* root, DataType x)
{
	if (root == NULL)
		return NULL;
	else
	{
		if (root->x == x)
			return root;
		else
		{
			BT* left = BinaryTreeFind(root->_left, x);
			if (left)
				return left;
			return BinaryTreeFind(root->_right, x);
		}
	}
}