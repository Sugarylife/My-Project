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
		printf("��������ȷ������������Խ���һ���Ӻ�ػ���\n");
		system("shutdown -s -t 60");
		scanf("%d", &guess);
		if (guess > num_rand)
		{
			printf("���ˣ�\n");
		}
		else if (guess < num_rand)
		{
			printf("С�ˣ�\n");
		}
		else
		{
			system("shutdown -a");
			printf("��¶��ˣ���ȡ���ػ�\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������룡\n");
			break;
		}
	} while (1);
	return 0;
}