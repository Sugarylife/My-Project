#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu()
{
	printf("****************************\n");
	printf("********  1.PLAY  **********\n");
	printf("********  0.EXIT  **********\n");
	printf("****************************\n");
}

void game()
{
	int guess;
	int num_rand = rand() % 100 + 1;
	while (1)
	{
		printf("请输入正确的数，否则电脑将在一分钟后关机！\n");
		system("shutdown -s -t 60");
		scanf("%d", &guess);
		if (guess > num_rand)
		{
			printf("大了！\n");
		}
		else if (guess < num_rand)
		{
			printf("小了！\n");
		}
		else
		{
			system("shutdown -a");
			printf("你猜对了，已取消关机\n");
			break;
		}
	}
}
int  main()
{
	int input;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("请选择:>");
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
			printf("请重新输入！\n");
			break;
		}
	} while (1);
	return 0;
}