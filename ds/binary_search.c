#include<stdio.h>

int binary_search(int num_ele, int *arr_ptr, int num)
{
	int left_index, right_index, mid_index;
	right_index = num_ele - 1;
	left_index = 0;
	mid_index = num_ele/2;
	while(left_index < num_ele && right_index > 0) {
		if(*(arr_ptr + mid_index) == num)
			return mid_index;
		else if (*(arr_ptr + mid_index) > num)
			right_index = mid_index - 1;
		else
			left_index = mid_index + 1;
		mid_index = (left_index + right_index)/2;
	}
	return -1;
}

int main(void)
{
	int num_ele, num, ret;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	num_ele = sizeof(arr)/sizeof(int);
	printf("Please enter the number to search in array\n");
	scanf("%d", &num);
	ret = binary_search(num_ele, arr, num);
	if(ret == -1)
		printf("num:%d not found in array\n", num);
	else
		printf("num:%d found at index:%d\n", num, ret);
	return 0;
}
