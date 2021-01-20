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
		printf("请注意，你的电脑将在1分钟后关机，输入“我是猪”取消关机\n");
		scanf("%s", input);
		if (0 == strcmp(input, "我是猪"))
		{
			system("shutdown -a");
			printf("已取消关机");
			break;
		}
		else
		{
			printf("请端正你的态度！\n");
		}
	}
	return 0;
}