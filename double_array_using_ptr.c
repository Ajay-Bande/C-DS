#include <stdio.h>
#include <stdlib.h>
int main()
{
#if 0
	/* using array of pointers */
	int row = 4, col = 4, i, j, *arr[row];
	static int count = 1;
	for(i=0 ;i < row; i++) {
		arr[i] = (int *) malloc (sizeof(int) * col);
	}
	
	/* assign value to the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			*(*(arr + i) + j) = count++;
			//arr[i][j]= count++;
		}
	}
	/* print the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			printf(" arr:%p arr+i:%p *(arr+i):%p (*(arr+i)+j):%p row: %d col:%d val:%d\n", arr, arr+i, *(arr+i), (*(arr+i)+j), i, j, *(*(arr + i) + j));
			//printf("row: %d col:%d val:%d\n", i, j, arr[i][j]);
		}
	}
	
#endif

#if 0
	/* using sinle pointer */
	int row = 4, col = 4, i, j, *arr;
	static int count = 1;
	arr = (int *) malloc (row * col * sizeof(int));
	/* assign value to the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			*((arr + i * col) + j) = count++;
		}
	}
	/* print the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			printf("arr:%p arr+i:%p ((arr+i * col)+j):%p row: %d col:%d val:%d\n", arr, arr+i, ((arr+i * col)+j), i, j, (*(arr + i * col) + j));
			//printf("row: %d col:%d val:%d\n", i, j, arr[i][j]);
		}
	}
#endif

#if 0	
	/* using pointer to pointer */
	int row = 4, col = 4, i, j, **arr;
	static int count = 1;
	arr = (int **) malloc (sizeof(int *) * row);
	for(i=0 ;i < row; i++) {
		*(arr+i) = (int *) malloc (sizeof(int) * col);
	}
	
	/* assign value to the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			*(*(arr + i) + j) = count++;
			//arr[i][j]= count++;
		}
	}
	/* print the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			printf(" arr:%p arr+i:%p *(arr+i):%p (*(arr+i)+j):%p row: %d col:%d val:%d\n", arr, arr+i, *(arr+i), (*(arr+i)+j), i, j, *(*(arr + i) + j));
			//printf("row: %d col:%d val:%d\n", i, j, arr[i][j]);
		}
	}
#endif
	/* using double pointer and one malloc for all row*/
	int row = 4, col = 4, i, j, **arr;
	static int count = 1;
	arr = (int **) malloc (sizeof(int *) * row);
	*arr = (int *) malloc (row * col * sizeof(int));
	for(i=0 ;i < row; i++) {
		*(arr+i) = (*arr + i * col);
	}
	/* assign value to the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			*(*(arr + i) + j) = count++;
			//arr[i][j]= count++;
		}
	}
	/* print the array */
	for(i=0 ;i < row; i++) {
		for(j = 0 ;j < col; j++) {
			printf(" arr:%p arr+i:%p *(arr+i):%p (*(arr+i)+j):%p row: %d col:%d val:%d\n", arr, arr+i, *(arr+i), (*(arr+i)+j), i, j, *(*(arr + i) + j));
			//printf("row: %d col:%d val:%d\n", i, j, arr[i][j]);
		}
	}

	return 0;
}
