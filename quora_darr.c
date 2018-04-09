#include <stdio.h>
#include <stdlib.h>

#if 0
void passing_arr_variab_para_print(int row, int col, int arr[][col])
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("row: %d col: %d val: %d \n", i, j, *(*(arr+i) +j));
		}
	}
}
#endif
#if 0
void passing_arr_sing_ptr_print(int row, int col, int *ptr)
{
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("row: %d col: %d val: %d \n", i, j, (*(ptr+i * col) +j));
		}
	}
}
#endif

#if 0
void arr_of_ptr_print(int **ptr, int row, int col)
{
	int i, j;
	static int count = 1;
	*ptr = (int *) malloc (sizeof(int) * col * row);	
	for (i = 0; i < row; i++) {
		*(ptr + i) = (*ptr + i *col);
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			*(*(ptr+i) +j) = count++;
		}
	}
}
#endif
	
#if 0
int **double_print(int **ptr, int row, int col)
{
	int i, j;
	static int count = 1;
	ptr = (int **) malloc (sizeof(int *) * row);	
	*ptr = (int *) malloc (sizeof(int) * col * row);	
	for (i = 0; i < row; i++) {
		*(ptr + i) = (*ptr + i *col);
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			*(*(ptr+i) +j) = count++;
		}
	}
	return ptr;
}
#endif

#if 0
int *single_print(int *ptr, int row, int col)
{
	int i, j;
	static int count = 1;
	ptr = (int *) malloc (sizeof(int) * row * col);	
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			*((ptr+i*col) +j) = count++;
		}
	}
	return ptr;
}
#endif

int main(void)
{
#if 0
	/* using single pointer */
	int row = 4, i, j;
	int col = 4;
	int *arr = NULL;
	arr = single_print(arr, row, col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("row: %d col: %d val: %d \n", i, j, *((arr+i*col) +j));
		}
	}
#endif
#if 0
	/* using double pointer */
	int row = 4, i, j;
	int col = 4;
	int **arr = NULL;
	arr = double_print(arr, row, col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("row: %d col: %d val: %d \n", i, j, *(*(arr+i) +j));
		}
	}
#endif
#if 0
	/* using array of pointer */
	int row = 4, i, j, *arr[row];
	int col = 4;
	arr_of_ptr_print(arr, row, col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("row: %d col: %d val: %d \n", i, j, *(*(arr+i) +j));
		}
	}
#endif
#if 0
	/* passing array using single ptr */
	int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
	passing_arr_sing_ptr_print(3, 3, (int *) arr);
#endif
#if 0
	/* passing array using variable parameter */
	int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
	int row = 3; int col = 3;
	passing_arr_variab_para_print(row, col, arr);
#endif
	/* passing array using single ptr */
	
	return 0;
}
