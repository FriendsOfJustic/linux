#pragma once
#define COL 3
#define ROW 3

void initboard(char board[][COL], int col, int row);                      //�����̳�ʼ��


void displayboard(char board[][COL], int col, int row);                   // ��ӡ����

void playermove(char board[][COL], int col, int row);                     //����ƶ�

void computermove(char board[][COL], int col, int row);                    //�����ƶ�

char check(char board[][COL], int col, int row);

int isfull(char board[][COL], int col, int row);
//�ж���Ӯ�� 1 ���Ӯ
//           2 ����Ӯ 
//           3 ƽ��
//           4 ���϶�û�з���������Ϸ��


















