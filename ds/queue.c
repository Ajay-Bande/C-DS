#include<stdio.h>
#define MAX_QUEUE_SIZE 10

void peek(int *fptr)
{
	if (fptr == NULL)
		printf("Queue is Empty\n");
	else
		printf("peek value is: %d \n", *fptr);
}

int size_of_queue(int *fptr, int *rptr)
{
	if (fptr == NULL && rptr == NULL)
		return 0;
	else if (fptr == rptr)
		return 1;
	else
		return ((rptr - fptr) + 1);
}

void display (int *fptr, int *rptr)
{
	int size, i = 0;
	if (fptr == NULL)
		printf("Queue is Empty\n");
	else {
		size = size_of_queue(fptr, rptr);
		while ( i < size ) {
			printf("Queue position:%d Value is: %d \n", i, *fptr);
			fptr++;
			i++;
		}
	}
}

int *dequeue(int *fptr, int **rptr)
{
	int size;
	size = size_of_queue(fptr, (int *) *rptr);
	if (size == 0)
		return NULL;
	else if ( size ==1 ) {
		*rptr = NULL;
		return NULL;
	} else
		return ++fptr;
}

int *enqueue(int *arr_ptr, int **fptr, int *rptr, int val)
{
	int size;
	size = size_of_queue((int *) *fptr, rptr);
	if(size >= MAX_QUEUE_SIZE) {
		printf("queue reach to max size\n");
		return rptr;
	}
	if (rptr == NULL) {
		*fptr= rptr = arr_ptr;
		*rptr = val;
		printf("rptr: %p *rptr: %d\n", rptr, *rptr);
	}
	else {
		rptr++;
		*rptr = val;
		printf("else rptr: %p *rptr: %d\n", rptr, *rptr);
	}
	return rptr;
}

int main(void)
{
	int *front = NULL;
	int *rear = NULL;
	int choice = 0, val, size;
	int arr[10] = {0};
	while(1) {
		printf("Welcome for queue oprations\n");
		printf("Please press :1 for Enqueue operation\n");
		printf("Please press :2 for to get size of Queue\n");
		printf("Please press :3 for Dequeue operation\n");
		printf("Please press :4 for peek operation\n");
		printf("Please press :5 for display operation\n");
		printf("Please press :6 for exit operation\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("please enter value for enque opration\n");
				scanf("%d", &val);
				rear = enqueue(arr, &front, rear, val);
				printf("ret_front: %p ret_rear:%p\n",front, rear);
				break;
			case 2:
				size = size_of_queue(front, rear);
				printf("size of queue is: %d\n", size);
				break;
			case 3:
				front = dequeue(front, &rear);
				if (front == NULL ){
					printf("Queue is empty\n");
				}
				break;
			case 4:
				peek(front);
				break;
			case 5:
				display(front, rear);
				break;
			case 6:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
