#pragma once
#define COL 9
#define ROW 9
#define COLS 11
#define ROWS 11
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//初始化棋盘
void initboard(char board[ROWS][COLS], int col, int row, char set);

//展示棋盘
void displayboard(char board[ROWS][COLS], int col, int row);


//设置地雷
void setMine(char board[ROWS][COLS], int col, int row);

//排地雷
int findMine(char board[ROWS][COLS], int col, int row);

//快速排除周围没有一个地雷的点
void fun(char board2[ROWS][COLS], char board1[ROWS][COLS], char board[ROWS][COLS], int x, int y);

void copy(char board[ROWS][COLS], char board1[ROWS][COLS], int col, int row);