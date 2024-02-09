#include<stdio.h>
void f1(int a);
void f2(int *);
void f3(int *b);
int main()
{
	int a = 100;
	printf("before a is %d\n",a);
	f3(&a);
	printf("after f1, a is %d\n",a);
	return 0;
}
void f1(int a)
{
	a = 200;
}

void f2(int *a)
{
	*a = 200;
}
void f3(int *a)
{
	printf("inside function %d\n",*a);
	int b = 200;
	a = &b;
	printf("end of the function %d\n",*a);
	
}