#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录最初只有0个内容
}

void AddContact(struct Contact* ps)
{
	if (MAX == ps->size)
	{
		printf("通讯录已满，无法继续输入\n");
	}
	else
	{
		printf("请输入姓名：>\n");
		scanf("%s", &(ps->data[ps->size].name));
		printf("请输入年龄：>\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：>\n");
		scanf("%s", &(ps->data[ps->size].sex));
		printf("请输入电话：>\n");
		scanf("%s", &(ps->data[ps->size].tele));
		printf("请输入地址：>\n");
		scanf("%s", &(ps->data[ps->size].addr));

		ps->size++;
		printf("添加成功！\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空!\n");
	}
	else
	{
		int i = 0;
		printf("%-6s\t%-4s\t%-5s\t%-12s\t%-8s\n", "名字", "年龄", "性别", "电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-6s\t%-4d\t%-5s\t%-12s\t%-8s\n",
				ps->data[i].name,
				ps->data[i].age, ps->data[i].sex,
				ps->data[i].tele, ps->data[i].addr);
		}
	}
}

 static int FindByName(struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到的情况
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字：>\n");
	scanf("%s", name);
	//查找要删除的人在什么位置
	//找到了返回名字所在元素的下标
	//找不到返回-1
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("要删除的人不存在！\n");
	}
	//开始删除
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
	}
	ps->size--;
	printf("删除成功!\n");
}

void SearchContact( struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字：>\n");
	scanf("%s", name);
	//查找
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("要查找的人不存在！\n");
	}
	else
	{
		printf("%-6s\t%-4s\t%-5s\t%-12s\t%-8s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-6s\t%-4d\t%-5s\t%-12s\t%-8s\n", ps->data[pos].name, ps->data[pos].age, ps->data[pos].sex, ps->data[pos].tele, ps->data[pos].addr);
	}
}

void ModifyContact(const struct Contact* ps)//修改指定联系人
{
	char name[MAX_NAME];
	printf("请输入要修改信息的姓名：>\n");
	scanf("%s",name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("要修改的信息不存在!\n");
	}
	else
	{
		printf("请输入要修改的信息：>\n");
		printf("姓名：>\n");
		scanf("%s",ps->data[pos].name);
		printf("年龄：>\n");
		scanf("%d",&(ps->data[pos].age));
		printf("性别：>\n");
		scanf("%s",ps->data[pos].sex);
		printf("电话：>\n");
		scanf("%s",ps->data[pos].tele);
		printf("地址：>\n");
		scanf("%s",ps->data[pos].addr);

		printf("修改成功！\n");
	}
}

void SortContact(struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - i; j++)
		{
			struct PeoInfo temp;
			int tmp;
			if (ps->data[j].age > ps->data[j + 1].age)
			{
				temp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = temp;

			}
		}
		printf("排序成功！\n");

	}
}