#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[10] = "";
	system("shutdown -s -t 60");
	while (1)
	{
		printf("��ע�⣬��ĵ��Խ���1���Ӻ�ػ������롰������ȡ���ػ�\n");
		scanf("%s", input);
		if (0 == strcmp(input, "������"))
		{
			system("shutdown -a");
			printf("��ȡ���ػ�");
			break;
		}
		else
		{
			printf("��������̬�ȣ�\n");
		}
	}
	return 0;
}