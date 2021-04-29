#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
void game()
{
	char board[ROW][COL];
	initboard(board, COL, ROW);
	displayboard(board, COL, ROW);
	while (1)
	{
		char ret;
		playermove(board, COL, ROW);
		displayboard(board, COL, ROW);
		ret = check(board, COL, ROW);
		if (ret == '*')
		{
			printf("玩家获胜！！");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑获胜！！！");
			break;
		}
		else if (ret == 'p')
		{
			printf("平局！！！");
			break;
		}

		computermove(board, COL, ROW);
		displayboard(board, COL, ROW);
		ret = check(board, COL, ROW);
		if (ret == '*')
		{
			printf("玩家获胜！！");
			break;
		}
		else if (ret == '#')
		{
			printf("电脑获胜！！！");
			break;
		}
		else if (ret == 'p')
		{
			printf("平局！！！");
			break;
		}
	}

}
void manu()
{
	printf("**********************************\n");
	printf("***********1. play     ***********\n");
	printf("***********2. exite    ***********\n");
	printf("**********************************\n");
	printf("**********************************\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	do
	{
		int n;
		manu();
		scanf("%d", &n);
		if (1 == n)
		{
			game();
		}
		else
			break;
	} while (1);
}