#pragma once
#define COL 9
#define ROW 9
#define COLS 11
#define ROWS 11
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//��ʼ������
void initboard(char board[ROWS][COLS], int col, int row, char set);

//չʾ����
void displayboard(char board[ROWS][COLS], int col, int row);


//���õ���
void setMine(char board[ROWS][COLS], int col, int row);

//�ŵ���
int findMine(char board[ROWS][COLS], int col, int row);

//�����ų���Χû��һ�����׵ĵ�
void fun(char board2[ROWS][COLS], char board1[ROWS][COLS], char board[ROWS][COLS], int x, int y);

void copy(char board[ROWS][COLS], char board1[ROWS][COLS], int col, int row);