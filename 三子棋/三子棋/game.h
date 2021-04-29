#pragma once
#define COL 3
#define ROW 3

void initboard(char board[][COL], int col, int row);                      //将棋盘初始化


void displayboard(char board[][COL], int col, int row);                   // 打印棋盘

void playermove(char board[][COL], int col, int row);                     //玩家移动

void computermove(char board[][COL], int col, int row);                    //电脑移动

char check(char board[][COL], int col, int row);

int isfull(char board[][COL], int col, int row);
//判断输赢： 1 玩家赢
//           2 电脑赢 
//           3 平局
//           4 以上都没有发生继续游戏，


















