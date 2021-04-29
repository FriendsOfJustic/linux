#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initboard(char board[ROW][COL], int col, int row)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void displayboard(char board[][COL], int col, int row)
{
	for (int i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			if (COL - j == 1)
			{
				printf(" %c \n", board[i][j]);
				break;
			}
			printf(" %c |", board[i][j]);
		}
		for (j = 0; j < COL; j++)
		{
			if (COL - j == 1)
			{
				printf(" - \n");
				break;
			}
			printf(" - |");
		}
	}
}

void playermove(char board[][COL], int col, int row)
{
	while (1)
	{
		int x, y;
		printf("玩家输入：");
		scanf("%d %d", &x, &y);
		if (board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = '*';
			break;
		}
		else
			printf("该坐标已经被占用");
	}
}

void computermove(char board[][COL], int col, int row)
{
	printf("电脑走；\n");
	while (1)
	{
		int x, y;
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char check(char board[][COL], int col, int row)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
		
	if ((board[0][0] == board[1][1]&&board[1][1]==board[2][2] && board[0][0] != ' ')||(board[0][2] == board[1][1] && board[1][1] == board[2][1] && board[0][2] != ' '))
		{
			return board[0][0];
		}
	int ret=isfull(board, COL, ROW);
	if (ret != 0)
		return 'p';
	return 'c';



}
int isfull(char board[][COL], int col, int row)
{
	int ret;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (board[i][j] != ' ')
				ret = 1;
			else
				return 0;
		}
	}
	if (ret == 1)
		return 1;
}