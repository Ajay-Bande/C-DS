#include <stdio.h>

void printarr(int *ptr, int element)
{
	int i;
	for (i= 0;i< element; i++) {
			printf("val:%d\n",*(ptr+i));
	}
}
int main()
{
	int arr[4]= {1,2,3,4};
	printarr(arr, 4);
	return 0;
}
