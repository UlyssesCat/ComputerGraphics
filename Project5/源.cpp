#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include <time.h> 
using namespace std;
void Bresenham(int x1, int y1, int x2, int y2, int color)
{
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int s1 = x2 > x1 ? 1 : -1;
	int s2 = y2 > y1 ? 1 : -1;
	bool changeFlag = false;	// 默认不互换 dx、dy
	if (dy > dx)				// 当斜率大于 1 时，dx、dy 互换
	{
		int temp = dx;
		dx = dy;
		dy = temp;
		changeFlag = true;
	}
	int e = -dx;
	for (int i = 0; i < dx; i++)
	{
		//Sleep(1);
		putpixel(x, y, color);

		if (!changeFlag)
		{
			x += s1;				
			e = e + 2 * dy;
			if (e >= 0)
			{
				y += s2;
				e -= 2 * dx;
			}
		}
		else
		{
			y += s2;				
			e = e + 2 * dy;
			if (e >= 0)
			{
				x += s1;
				e -= 2 * dx;
			}
		}	
	}
}

void main()
{
	const int a = 600, b = 400, k = 20;//个数
	initgraph(a, b);
	int x1[k];
	int y1[k];
	int x2[k];
	int y2[k];
	srand((unsigned)time(NULL));
	for (int i = 0; i < k; i++)
		x1[i] = (rand() % (a + 1));
	for (int i = 0; i < k; i++)
		y1[i] = (rand() % (b + 1));
	for (int i = 0; i < k; i++)
		x2[i] = (rand() % (a + 1));
	for (int i = 0; i < k; i++)
		y2[i] = (rand() % (a + 1));
	for (int i = 0; i < k; i++)
		Bresenham(x1[i], y1[i], x2[i], y2[i], GREEN);
	_getch();
	closegraph();
}