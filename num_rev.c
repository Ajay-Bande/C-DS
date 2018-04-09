#include<stdio.h>
int main(void)
{
	int num = 0, sum = 0, rem = 0;
	printf("please enter number\n");
	scanf("%d %x", &num, &num);
	while(num !=0 ) {
		rem = num % 16;
		sum = sum *16 + rem;
		num = num / 16;
	}
	printf("sum:%d %x\n", sum, sum);

	return 0;
}
