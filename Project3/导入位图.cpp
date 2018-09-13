#include <graphics.h>
#include <conio.h>

void main()
{
	initgraph(400, 300);

	// 定义 IMAGE 对象
	IMAGE img;


	loadimage(&img, L"D://2.jpg",400,300);	// 读取图片到 img 对象中
	putimage(0, 0, &img);	// 在坐标 (0, 0) 位置显示 IMAGE 对象

	//// 绘制内容
	//circle(100, 100, 20);
	//line(70, 100, 130, 100);
	//line(100, 70, 100, 130);

	//// 保存区域至 img 对象
	//getimage(&img, 70, 70, 60, 60);

	//// 将 img 对对象显示在屏幕的某个位置
	//putimage(200, 200, &img);

	_getch();
	closegraph();
}