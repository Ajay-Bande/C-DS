#include<stdio.h>

int main (void)
{
	unsigned char num = 4;
	unsigned char num1 = 4;
	unsigned char num2 = 4;
	unsigned char num3 = 4;
	num = num | (1 << 1);
	printf("Setting bit:%d\n", num);
	num1 = num1 & ~(1 << 2);
	printf("Clear bit:%d\n", num1);
	num2 = num2 ^ (1 << 3);
	printf("Toggle bit:%d\n", num2);
	num3 = (num3 >> 2) & 1;
	printf("Get bit:%d\n", num3);
	return 0;
}
