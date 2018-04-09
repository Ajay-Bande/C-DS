#include<stdio.h>

void add(void)
{
	int a = 10;
	int b = 20;
	static int i;
	i = a + b;
	printf("i:%d\n",i);
}

void mul(void)
{
	int a = 10;
	int b = 20;
	static int i;
	i = a * b;
	printf("i:%d\n",i);
}

int main(void)
{
	add();
	mul();
	return 0;
}
