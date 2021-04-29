#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void initboard(char board[ROWS][COLS], int col, int row, char set)
{
	int i = 0, j = 0;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			board[j][i] = set;
		}
	}

}

void displayboard(char board[ROWS][COLS], int col, int row)
{
	int i = 0, j = 0;
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <=col; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= row; j++)
		{
			printf("%c ", board[j][i]);
		}
		printf("\n");
	}
}


void setMine(char board[ROWS][COLS], int col, int row)
{
	int x, y;
	int n = 1;
	while (n<=10)
	{
		x = rand() % (col - 1) + 1;
		y = rand() % (row - 1) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			n++;

		}
	}
}
int findMine(char board[ROWS][COLS], int x, int y)
{
	while (1)
	{
		if (board[x][y] == '1')
		{
			return 10;
		}
		else
		{
			return board[x - 1][y - 1] +
				board[x][y - 1] +
				board[x + 1][y - 1] +
				board[x - 1][y] +
				board[x + 1][y] +
				board[x - 1][y + 1] +
				board[x][y + 1] +
				board[x + 1][y + 1] - 8 * board[x][y];
		}
	}

}



void fun(char board2[ROWS][COLS],char board1[ROWS][COLS],char board[ROWS][COLS], int x, int y)                 //fun(botboard, showboard, botboard, x, y);
{
	int ret = findMine(board, x, y);
	if (ret == 0 && x > 0 && y > 0 && board2[x][y] != ' ')
	{
		board2[x][y] = ' ';
		board1[x][y] = ' ';
		fun(board2, board1, board, x - 1, y);
		fun(board2, board1, board, x + 1, y);
		fun(board2, board1, board, x, y + 1);
		fun(board2, board1,board, x, y - 1);
	}
	board1[x][y] = ret + '0';
}

void copy(char board[ROWS][COLS], char board1[ROWS][COLS],int col,int row)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = board1[i][j];
		}
	}
}