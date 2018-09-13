#include <gl/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

GLint flag = 1;
GLfloat ori[2]; //起点坐标
GLfloat next[2];//终点坐标
GLfloat dir[2] = { 1,0 };//方向向量
GLint D = 100;//直线长度
GLfloat angle = 30 * 3.1415926 / 180.0;//旋转角度
GLint n = 1;//直线旋转角度次数

void init()
{
	flag = 1;
	dir[0] = 1;
	dir[1] = 0;
	D = 100;
	n = 1;
}

void myDisplay(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (flag == 1)
	{
		glBegin(GL_POINTS);//画点
		glVertex2f(ori[0], 400 - ori[1]);
		glEnd();
	}
	if (flag == 2)
	{
		glBegin(GL_LINES);//画线
		glVertex2f(ori[0], 400 - ori[1]);
		glVertex2f(next[0], 400 - next[1]);
		glEnd();
	}
	glFlush();
}

void myMouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			ori[0] = x;
			ori[1] = y;
			init();
			glutPostRedisplay();
			break;
		}
	}
}

void updata()
{
	if (flag == 1)
	{
		next[0] = ori[0] + D * dir[0];
		next[1] = ori[1] + D * dir[1];
		flag = 2;
	}
	else
	{
		next[0] = ori[0] + D * dir[0];
		next[1] = ori[1] - D * dir[1];
	}
	glutPostRedisplay();
}
void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'f':
	{
		if (flag == 1)
			updata();
		break;
	}
	case 't':
	{
		if (flag == 2)
		{
			dir[0] = cos(angle * n);
			dir[1] = sin(angle * n);
			n++;
			updata();
		}
		break;
	}

	case 'i':
	{
		D = D * 2;
		updata();
		break;
	}
	case 's':
	{
		D = D * 0.5;
		updata();
		break;
	}
	case 'r':
	{
		glColor3f(1, 0, 0);
		glutPostRedisplay();
		break;
	}
	case 'g':
	{
		glColor3f(0, 1, 0);
		glutPostRedisplay();
		break;
	}
	case 'b':
	{
		glColor3f(0, 0, 1);
		glutPostRedisplay();
		break;
	}
	case 27:
		exit(0);
	}
}

void myKeyboard1(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	{
		ori[0] -= 5;
		next[0] -= 5;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_UP:
	{
		ori[1] -= 5;
		next[1] -= 5;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		ori[0] += 5;
		next[0] += 5;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_DOWN:
	{
		ori[1] += 5;
		next[1] += 5;
		glutPostRedisplay();
		break;
	}
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)w, 0, (GLdouble)h);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("第一个OpenGL程序");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(myKeyboard1);
	glutMouseFunc(myMouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}