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
		printf("���������֣�>");
		scanf("%d", &a);
		if (a > num)
		{
			printf("���ˣ�\n");
		}
		else if (a < num)
		{
			printf("С�ˣ�\n");
		}
		else
		{
			printf("�¶��ˣ�\n");
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
		printf("��ѡ��>");
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
			printf("����������\n");
			break;
		}
	} while (input);
	return 0;
}