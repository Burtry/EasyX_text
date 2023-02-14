#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5 
#define MAX_TELE 12
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
struct Peoinfo
{
	char name[MAX_NAME];				//姓名
	char sex[MAX_SEX];					//性别
	int age;							//年龄
	char tele[MAX_TELE];				//电话	
	char addr[MAX_ADDR];				//地址
};
struct Contact
{
	struct Peoinfo data[MAX];
	int size;
};

enum Option
{
	EXIT, //0
	ADD,//1
	DEL,//2
	SHOW,//3
	MODIFY,//4
	SEARCH,//5
	SORT
};

//声明函数
//初始化通讯录
void Initcontect(struct Contact* ps);
//增加人员信息
void Addpeople(struct Contact* ps);
//展示人员信息
void ShowContect(const struct Contact* ps);
//修改人员信息
void ModifyContact(struct Contact* ps);
//删除人员信息
void Delpeople(struct Contact* ps);
//查询人员信息
void SearchPepole(const struct Contact *ps);