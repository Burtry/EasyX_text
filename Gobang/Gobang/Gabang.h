#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<easyX.h>
#include<graphics.h>
#include<conio.h>

#define BOARD_SIZE 15								   // ���̴�С
#define GRID_SIZE  30								   // ���̸��Ӵ�С
#define LEFT_MARGIN  60								   // ������߾�
#define RIGHT_MARGIN (60 + GRID_SIZE * BOARD_SIZE)     // �����ұ߾�
#define TOP_MARGIN  60								   // �����ϱ߾�
#define BOTTOM_MARGIN  (60 + GRID_SIZE * BOARD_SIZE)   // �����±߾�


int board[BOARD_SIZE][BOARD_SIZE];  // ����״̬���飬��ʼֵΪ0

//��������
void Drew_board(void);
//�ڽ��洦���������
void getNearestCross(int x, int y, int& i, int& j);
//����
void PlayGame(void);
//���ʤ��
int ChearWin(int player);