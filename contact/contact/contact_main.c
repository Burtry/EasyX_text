#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include"contact.h"
void menu()
{
	printf("***************************************\n");
	printf("***1.add              2.del         ***\n");
	printf("***3.show             4.modify      ***\n");
	printf("***5.search           6.sort        ***\n");
	printf("***0.exit                           ***\n");
	printf("***************************************\n");

}
int main()
{
	int input = 0;
	struct Contact con;
	//初始化通讯录
	Initcontect(&con);
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:	Addpeople(&con);	//增加人员信息
			break;
		case DEL:	 Delpeople(&con);	//删除人员信息
			break;
		case SHOW:	 ShowContect(&con);   //展示信息
			break;
		case MODIFY:	ModifyContact(&con);  //修改信息
			break;
		case SEARCH: SearchPepole(&con);
			break;
		case SORT :
			break;
		case EXIT:
			printf("退出程序\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		
	} while (input);

	return 0;
}
