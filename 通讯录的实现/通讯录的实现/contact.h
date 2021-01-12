#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};


//进行选项可读化
enum Option
{
	EXIT,//0
	ADD,//1
	DELET,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};

//声明函数
void InitContact(struct Contact* ps);//初始化通讯录的函数
void AddContact(struct Contact* ps);//增加信息的函数
void ShowContact(const struct Contact* ps);//打印通讯录的信息的函数
void DelContact(struct Contact* ps);//删除指定的联系人
void SearchContact( struct Contact* ps);//查找指定的联系人
void ModifyContact(const struct Contact* ps);//修改指定联系人的信息
void SortContact(struct Contact* ps);//对通讯录联系人进行年龄排序
