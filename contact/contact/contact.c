#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include"contact.h"
void Initcontect(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void Addpeople(struct Contact* ps)
{
	if (ps->size == 1000)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);
	
		ps->size++;
		printf("添加成功\n");
	}
}
void ShowContect(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
		for (i = 0; i<(ps->size); i++)
		{
			printf("%-20s\t%-4s\t%-5d\t%-12s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);

		}
	}
}
void ModifyContact(struct Contact* ps)
{


}
void Delpeople(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入删除人员的名字:");
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name,name))
		{
			break;
		}
	}
	if (i == ps->size)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = i; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchPepole(const struct Contact* ps)
{


}
