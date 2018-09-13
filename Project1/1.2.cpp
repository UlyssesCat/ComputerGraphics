#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include <time.h> 
using namespace std;

void AIntegerBresenhamline(int x0, int y0, int x1, int y1, int color)
{
	int x, y, dx, dy, e;
	dx = x1 - x0;//起点终点x之差
	dy = y1 - y0;//起点终点y之差
	e = -dx;//一开始e为d（误差与±0.5比较，然后让e初始值为-0.5，就可以跟0~1，与0比较，再*2 *dx, 最后e=-dx【e=e+k   e=e+ dy/dx  e'=e'+2dy】）
	x = x0;
	y = y0;
	for (int i = 0; i <= dx; i++)
	{
		//Sleep(5);
		putpixel(x, y, color);
		x++;
		e = e + 2 * dy;
		if (e >= 0) { y++; e = e - 2 * dx; }
	}

}

void BIntegerBresenhamline(int x0, int y0, int x1, int y1, int color)
{
	int x, y, dx, dy, e;
	dx = x1 - x0;//起点终点x之差
	dy = y1 - y0;//起点终点y之差
	e = -dx;//一开始e为d（误差与±0.5比较，然后让e初始值为-0.5，就可以跟0~1，与0比较，再*2 *dx, 最后e=-dx【e=e+k   e=e+ dy/dx  e'=e'+2dy】）
	x = x0;
	y = y0;
	for (int i = 0; i <= dx; i++)
	{
		//Sleep(5);
		putpixel(x, y, color);
		x++;
		e = e + 2 * dy;
		if (e >= 0) { y++; e = e - 2 * dx; }
	}

}

void main()
{
	

	const int a = 600;
	const int b = 400;
	const int k =10;//端点个数

	initgraph(a, b);

	int x0[k];
	int y0[k];
	int x1[k];
	int y1[k];


	srand((unsigned)time(NULL));

	for (int i = 0; i < k; i++)
		x0[i] = (rand() % (a + 1));
	
	for (int i = 0; i < k; i++)
		y0[i] = (rand() % (b + 1));
	
	for (int i = 0; i < k; i++)
		x1[i] = (rand() % (a + 1));

	for (int i = 0; i < k; i++)
		y1[i] = (rand() % (a + 1));

	for (int i = 0; i < k; i++)
	{
		float c;
		float dx = x1[i] - x0[i];
		float dy = y1[i] - y0[i];
		c = dy / dx;
		if (c <= 1 && c >= -1)
		{
			AIntegerBresenhamline(x0[i], y0[i], x1[i], y1[i], GREEN);
		}
		else
		{
			BIntegerBresenhamline(y0[i], x0[i], y1[i], x1[i], RED);
		}
	}

	_getch();
	closegraph();
}