#include<stdio.h>
#define mysizeof(size) ((char *) (&size + 1) - (char *) (&size))
int main(void)
{
	int x[10] = {0};
	printf("size_of int:%d\n",mysizeof(x));
	return 0;
}
