#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10
//初始化棋盘
//board  要初始化的数组
//rows   初始化二维数组的行
//cols   初始化二维数组的列
//set    要将面板初始化的字符
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印面板
//row    面板的行数
//col    面板的列数
void PrintBoard(char board[ROWS][COLS], int row, int col);

//设置雷
void SetMine(char board[ROWS][COLS], int row, int col, int count);

//排雷
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);