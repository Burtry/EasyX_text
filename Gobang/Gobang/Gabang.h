#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<easyX.h>
#include<graphics.h>
#include<conio.h>

#define BOARD_SIZE 15								   // 棋盘大小
#define GRID_SIZE  30								   // 棋盘格子大小
#define LEFT_MARGIN  60								   // 棋盘左边距
#define RIGHT_MARGIN (60 + GRID_SIZE * BOARD_SIZE)     // 棋盘右边距
#define TOP_MARGIN  60								   // 棋盘上边距
#define BOTTOM_MARGIN  (60 + GRID_SIZE * BOARD_SIZE)   // 棋盘下边距


int board[BOARD_SIZE][BOARD_SIZE];  // 棋盘状态数组，初始值为0

//绘制棋盘
void Drew_board(void);
//在交叉处最近处下棋
void getNearestCross(int x, int y, int& i, int& j);
//下棋
void PlayGame(void);
//检查胜负
int ChearWin(int player);