#include<stdio.h>
int main(void)
{
	int i = 1;
	char *ptr = (char *)&i;
	if (*ptr)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
	return 0;
}
