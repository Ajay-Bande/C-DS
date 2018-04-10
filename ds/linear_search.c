#include<stdio.h>
#include<stdlib.h>

int linear_search(int num, int num_ele, int *arr_ptr, int *index)
{
	int i;
	for(i = 0; i < num_ele; i++) {
		if(*(arr_ptr+i) == num) {
			*index = i;
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int num_ele, num, arr_ele, ret, i, index;
	int *arr_ptr = NULL;
	printf("Plese enter number of elements in arr\n");
	scanf("%d",&num_ele);
	arr_ptr = (int *) malloc (sizeof(int) * num_ele);
	if (arr_ptr == NULL) {
		printf("Error in allocation of array memory\n");
		exit(0);
	}
	for(i = 0; i < num_ele; i++) {
		printf("Please enter array element at index:%d\n", i);
		scanf("%d", &arr_ele);
		*(arr_ptr + i) = arr_ele;
	}
	printf("Plese enter number to be search arr\n");
	scanf("%d",&num);
	ret = linear_search(num, num_ele, arr_ptr, &index);
	if(ret)
		printf("%d number not found in array\n", num);
	else
		printf("%d number found at index:%d\n", num, index);

	return 0;
}
