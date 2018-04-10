#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *creat_node(int val)
{
	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));
	ptr->val =val;
	ptr->next = NULL;
	return ptr;
}

struct node *dequeue(struct node *fptr, struct node **rptr, int *ll_len_ptr)
{
	struct node *temp;
	if (fptr == NULL)
		return NULL;
	else if (*ll_len_ptr == 1) {
		temp = fptr;
		fptr = *rptr = NULL;
		--*ll_len_ptr;
		free(temp);
	} else {
		temp = fptr;
		fptr = fptr ->next;
		--*ll_len_ptr;
		free(temp);
	}
	return fptr;
}

struct node *enqueue(struct node **fptr, struct node *rptr, int *ll_len_ptr, int val)
{
	struct node *temp;
	temp = creat_node(val); 
	if ((rptr == NULL) && (*fptr == NULL)) {
		*fptr = rptr = temp;
		rptr -> val = temp->val;
	}
	else {
		rptr = rptr -> next = temp;
		rptr -> val = temp->val;
	}
	++*ll_len_ptr;
	return rptr;	
}

void peek(struct node *fptr)
{
	if(fptr == NULL)
		printf("Queue is empty\n");
	else
		printf("val: %d addr:%p\n", fptr->val, fptr->next);
		
}

void display(struct node *fptr)
{
	struct node *trav;
	trav = fptr;
	if(fptr == NULL) {
		printf("Queue is empty\n");
	}
	else {
		while(trav != NULL) {
			printf("val: %d addr:%p\n", trav->val, trav->next);
			trav = trav->next;
		}
	}
}

int main(void)
{
	struct node *front = NULL;
	struct node *rear = NULL;
	int val = 0;
	int ll_len = 0;
	while (1) {
		printf("Please enter :1 for enqueue opration\n");
		printf("Please enter :2 for dequeue opration\n");
		printf("Please enter :3 for peek opration\n");
		printf("Please enter :4 to get the size of queue\n");
		printf("Please enter :5 for display queue opration\n");
		printf("Please enter :6 for exit opration\n");
		printf("Please enter the operation number\n");
		if (scanf("%d", &val) <= 0 ) {
			printf("Please enter only unsigned int value\n");
			exit(0);
		}
		else {
			switch(val) {
				case 1:
					printf("Please enter value\n");
					scanf("%d", &val);
					rear = enqueue(&front, rear, &ll_len, val);
					break;
				case 2:
					front = dequeue(front, &rear, &ll_len);
					if ( front == NULL)
						printf(" Queue is Empty\n");
					break;
				case 3:
					peek(front);
					break;
				case 4:
					printf("Size of queue is: %d\n", ll_len);
					break;
				case 5:
					display(front);
					break;
				case 6:
					return 0;
					break;
				default :
					printf("Please enter valid operation\n");
			}
		}
	}
	return 0;
}
