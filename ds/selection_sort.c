#include<stdio.h>

void selection_sort(int *aptr, int size)
{
	int i, j, temp;
	for(i = 0; i < size; i++) {
		for(j = i; j < size; j++) {
			if( *(aptr + i) > *(aptr + j + 1)) {
				temp = *(aptr + i);
				*(aptr + i) = *(aptr + j + 1);
				*(aptr + j + 1) = temp;
			}
		}
	}
}

int main(void)
{
	int arr[5] = {7, 5, 4, 3, 1};
	int size, i;
	size = sizeof(arr)/sizeof(int);
	selection_sort(arr, size);
	for(i = 0; i < size; i++) {
		printf("index:%d value:%d\n", i, arr[i]);
	}
	return 0;
}
