#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
//#include<graphics.h>
#include<conio.h>
#include<easyx.h>

//具有观赏性的图形
void button(int x, int y, int w, int h,const char* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(BROWN);
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(30,0,"黑体");
	char text_[50] = "button";
	strcpy(text_, text);
	int tx = x +( w - textwidth(text))/2;
	int ty = y + (h - textheight(text))/2;
	outtextxy(tx, ty, text_);

}
int main()
{
	initgraph(1280, 720,EX_SHOWCONSOLE); 
	button(50, 50, 150, 50,"按钮");
	

	ExMessage msg;
	while (true)
	{


		if (peekmessage(&msg, EX_MOUSE))
		{

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 50 && msg.x <= 50 + 150 && msg.y >= 50 && msg.y <= 50 + 50)
				{
					printf("点击效果\n");
				}
				break;
			default:
				break;
			}
		}
	}
	_getch();				// 按任意键继续
	closegraph();	// 关闭绘图窗口
	return 0;
}

/*IMAGE background;
	loadimage(&background,
		_T("./jpg/oo.png",1000,1000),
		1280,
		720);
	putimage(0, 0, &background);*/

//int main()
//{
//	initgraph(1280, 720);
//	circle(50, 50, 50);
//	setlinestyle(PS_SOLID, 5);
//	setfillcolor(RED);
//	setlinecolor(BLUE);
//	fillcircle(50, 150, 50);
//	
//	solidcircle(50, 250, 50);
//	settextcolor(RGB(220, 207, 124));
//	//设置背景风格
//	settextstyle(30,30,"楷体");
//	//设置背景模式 trans parent
//	setbkmode(TRANSPARENT);
//	outtextxy(50, 5, "dfgerfgrrge");
//	//文字居中
//	fillrectangle(100,60,700,100);// 画一个矩形
//	char arr[] = "恶贼辛苦的的使用";
//	int width =  600/2-textwidth(arr)/2;
//	int height = 40/2-textheight(arr)/2;
//	outtextxy(width+100,height+60,arr);
//
//	getchar();
//	closegraph();
//	return 0;
//}





//int main()
//{
//	
//	initgraph(1280, 720);
//	setorigin(200, 200);
//
//		//setbkcolor();	cleardevice();  //设置背景为蓝色
//		setcolor(RED);
//		HRGN rgn = CreateRectRgn(100, 100, 200, 200);
//
//		rectangle(100, 100, 300, 200);
//		wchar_t s[] = L"Hello World";
//		outtextxy(10, 20, s);
//
//		graphdefaults();			
//		getchar();//
//		setbkcolor(WHITE);  cleardevice();
//		setcolor(BLUE);
//		rectangle(100, 100, 300, 200);
//	
//		outtextxy(10, 20, s);
//
//	getchar();
//	closegraph();
//
//	return 0;
//}
//int main()
//{
//    initgraph(640, 480);
//    setcolor(RED);
//    rectangle(100, 100, 300, 200);
//
//    _getch();
//    graphdefaults();
//    setcolor(BLUE);
//    rectangle(400, 100, 600, 200);
//    _getch();
//    closegraph();
//    return 0;
//}

//void text()
//{
//
//	initgraph(1280, 720);	// 创建绘图窗口，大小为 640x480 像素
//	setbkcolor(WHITE);
//	cleardevice(); //先设置背景颜色，再用当前背景色清空绘图设备，即可达到想要的颜色设置
//	
//	graphdefaults();
//
//
//	//setbkcolor(RED);
//	//cleardevice();
//	_getch();				// 按任意键继续
//	closegraph();			// 关闭绘图窗口
//}
//	//circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
	



//int main()
//{
//	text();
//	return 0;
//}