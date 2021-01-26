#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------扫  雷------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = +'1';
			count--;
		}
	}
}

int AroundMine(char mine[ROWS][COLS], int x, int y)//统计mine数组（x,y）坐标周边雷的个数
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row * col - COUNT)
	{
		printf("请输入要排除的坐标：");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法性
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你踩雷了\n");
				PrintBoard(mine, row, col);
				break;
			}
			if (mine[x][y] == '0')//如果不是雷，统计周边雷的个数
			{
				int count = AroundMine(mine, x, y);
				show[x][y] = count + '0';  //存放的是数字字符
				PrintBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("恭喜你，排雷成功！\n");
	}
}