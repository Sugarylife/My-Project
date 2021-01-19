#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void menu()
{
	printf("************************\n");
	printf("******  1. play  *******\n");
	printf("******  0. exit  *******\n");
	printf("************************\n");
}

void game()
{
	int a,num;
	num = rand() % 100 + 1;
	while (1)
	{
		printf("请输入数字：>");
		scanf("%d", &a);
		if (a > num)
		{
			printf("大了！\n");
		}
		else if (a < num)
		{
			printf("小了！\n");
		}
		else
		{
			printf("猜对了！\n");
			break;
		}
	}
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}