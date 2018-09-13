#include<iostream>
#include<string>
#pragma warning(disable : 4996)
using namespace std;

//class CPrintString
//{
//public:
//	CPrintString() {};
//	~CPrintString() {};
//
//public:
//	void PrintfText(const char* s) { printf(s); };
//	static void StaticPrintText(void* ptClass, const char* s);
//};
//void CPrintString::StaticPrintText(void* ptClass, const char* s)
//{
//	CPrintString* ptThis = static_cast<CPrintString*>(ptClass);
//	if (NULL == ptClass)
//	{
//		return;
//	}
//
//	ptThis->PrintfText(s);
//}
//
//typedef void(*PPRINTTEXT)(void* ptClass, const char* s);
//void CallPrintText(void* ptClass, const char *s, PPRINTTEXT fp)
//{
//	fp(ptClass, s);
//}



char * inputa()
{
	char  str[20] = "123";
	return str;
}
char * inputb()
{
	char * str = "123";
	return str;
}


class Father
{
private:int a;
public:int b;
protected:int c;
};
class Son :public Father
{
public:
	void foo()
	{
		//a = 1;
		b = 1;
		c = 1;
		Son s;
		s.c = 1;
	}
};
int main()
{
	Son s;
	s.foo();
	//const char* p1 = "123456";
	//char* p2 = p1 + 2;
	//char*p2 = p1;

	//p2 += 2;
	//*p2 = '\0';
	//cout << p1;






	/*char * p = inputb();
	cout <<inputa()<<"\n"<< p << endl;*/
	//const int a[4] = { 1,2,3 };
	//char  p[5]  ;
	//
	//cout << strlen(strcpy(p, "ABCD"));

	/*char* s = 1,2,3"abcd";
	fun(s);
	cout << s;*/
	/*int count = 0;
	while (count++ < 5) { int i = 0; cout << i++; }*/


	//CPrintString obj;
	//CallPrintText((void*)&obj, "Hello World!\n", CPrintString::StaticPrintText);
	/*int a = 1;
	int b = 1000;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
		cout << (rand() % (b - a + 1)) + a << '\t';

	cout << "\n";
	

	
	for (int i = 0; i < 10; i++)
		cout << (rand() % (b - a + 1)) + a << '\t';

	cout << "\n";


	for (int i = 0; i < 10; i++)
		cout << (rand() % (b - a + 1)) + a << '\t';

	cout << "\n";


	for (int i = 0; i < 10; i++)
		cout << (rand() % (b - a + 1)) + a << '\t';
	cout << endl;*/

}