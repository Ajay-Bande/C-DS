#include<stdio.h>
#define MAX_QUEUE_SIZE 10

void peek(int *tptr)
{
	if (tptr == NULL)
		printf("stack is Empty\n");
	else
		printf("peek value is: %d \n", *tptr);
}

int size_of_stack(int *tptr, int *bptr)
{
	if (tptr == NULL && bptr == NULL)
		return 0;
	else if (tptr == bptr)
		return 1;
	else
		return ((tptr - bptr) + 1);
}

void display (int *tptr, int *bptr)
{
	int size, i = 0;
	if (tptr == NULL)
		printf("stack is Empty\n");
	else {
		size = size_of_stack(tptr, bptr);
		while ( i < size ) {
			printf("stack position:%d Value is: %d \n", i, *tptr);
			tptr--;
			i++;
		}
	}
}

int *pop(int *tptr, int **bptr)
{
	int size;
	size = size_of_stack(tptr, (int *) *bptr);
	if (size == 0)
		return NULL;
	else if ( size ==1 ) {
		*bptr = NULL;
		return NULL;
	} else
		return --tptr;
}

int *push(int *arr_ptr, int *tptr, int **bptr, int val)
{
	int size;
	size = size_of_stack(tptr, (int *) *bptr);
	if(size >= MAX_QUEUE_SIZE) {
		printf("stack reach to max size\n");
		return tptr;
	}
	if (*bptr == NULL) {
		*bptr= tptr = arr_ptr;
		*tptr = val;
	}
	else {
		tptr++;
		*tptr = val;
	}
	return tptr;
}

int main(void)
{
	int *top = NULL;
	int *bottom = NULL;
	int choice = 0, val, size;
	int arr[10] = {0};
	while(1) {
		printf("Welcome for stack oprations\n");
		printf("Please press :1 for push operation\n");
		printf("Please press :2 for to get size of stack\n");
		printf("Please press :3 for pop operation\n");
		printf("Please press :4 for peek operation\n");
		printf("Please press :5 for display operation\n");
		printf("Please press :6 for exit operation\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("please enter value for push opration\n");
				scanf("%d", &val);
				top = push(arr, top, &bottom, val);
				break;
			case 2:
				size = size_of_stack(top, bottom);
				printf("size of stack is: %d\n", size);
				break;
			case 3:
				top = pop(top, &bottom);
				if (top == NULL ){
					printf("stack is empty\n");
				}
				break;
			case 4:
				peek(top);
				break;
			case 5:
				display(top, bottom);
				break;
			case 6:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
