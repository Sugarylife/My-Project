#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("****** Minesweeper ******\n");
	printf("******    1.PLAY   ******\n");
	printf("******    2.EXIT   ******\n");
	printf("*************************\n");

}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');//��ʼ��ɨ���ڲ�����
	InitBoard(show, ROWS, COLS, '*');//��ʼ��ɨ���������

	//PrintBoard(mine, ROW, COL);//��ӡɨ���ڲ�����
	PrintBoard(show, ROW, COL);//��ӡɨ�����

	SetMine(mine, ROW, COL, COUNT);//����
	//PrintBoard(mine, ROW, COL);

	FineMine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:\n");
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
			printf("ѡ���������������\n");
			break;
		}
	} while (input);
	return 0;
}