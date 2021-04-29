#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
void game()
{
	char showboard[ROWS][COLS] = { 0 };
	char botboard[ROWS][COLS] = { 0 };
	initboard(showboard, COLS, ROWS, '*');
	initboard(botboard, COLS, ROWS, '0');
	setMine(botboard, COL, ROW);
	char botboard2[ROWS][COLS];
	copy(botboard2, botboard, COL, ROW);
	displayboard(botboard, COL, ROW);
	int x, y;
	int  n = 0;
	while (1)
	{
		displayboard(showboard, COL, ROW);
		printf("请输入坐标值：");
		scanf("%d%d", &x, &y);

		if (x > 0 && x <=COL  && y > 0 && y <= COL)
		{
			n++;
			int ret = findMine(botboard, x, y);
			if (ret == 10)
			{
				showboard[x][y] = '#';
				printf("你被炸死了！！\n");
				break;
			}
			if (n == COL * ROW - 10)
			{
				printf("你获得了胜利\n");
				break;
			}
			if (ret == 0)
			{
				fun(botboard2, showboard, botboard, x, y);
			}
			else
			{
				showboard[x][y] = ret + '0';
				continue;
			}
		}
		printf("坐标错误！\n");
	}
	displayboard(showboard, COL, ROW);
	//displayboard(botboard, COL, ROW);

}
void manu()
{
	printf("***************************\n");
	printf("***************************\n");
	printf("*******1 . play************\n");
	printf("*******2 . excite**********\n");
	printf("***************************\n");
	printf("***************************\n");
}
int main()
{
	int n;
	srand((unsigned)time(NULL));
	do
	{
		manu();
		printf("玩家请选择：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 2:
			n = 0;
			break;
		default:
			n = 0;
			break;
		}

	} while (n);
}