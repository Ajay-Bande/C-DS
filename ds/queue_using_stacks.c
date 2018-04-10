#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct queue {
	struct node *stack1;
	struct node *stack2;
};

struct queue *create_queue(void)
{
	struct queue *qptr = NULL;
	qptr = (struct queue *) malloc(sizeof(struct queue));
	return qptr;
}

struct node *creat_node(int val)
{
	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));
	ptr->val =val;
	ptr->next = NULL;
	return ptr;
}

int pop(struct node **tptr)
{
	int val;
	struct node *temp;
	if (*tptr == NULL) {
		printf("stack 2 is empty\n");
	}
	else {
		temp = *tptr;
		val = temp->val;
		*tptr = temp->next;
		free(temp);
	}
	return val;
}

void push(struct node **tptr, int val)
{
	struct node *temp;
	temp = creat_node(val); 
	if (temp == NULL) {
		printf("Stack overflow\n");
	}
	temp->next = *tptr;
	*tptr = temp;
}

void enqueue(struct queue *qptr, int val)
{
	push(&qptr->stack1, val);
}

int dequeue( struct queue *qptr)
{
	int val;
	if(qptr->stack1 == NULL && qptr->stack2 == NULL) {
		printf("queue is empty\n");
	}
	if(qptr->stack2 == NULL) {
		while(qptr->stack1 != NULL) {
			val = pop(&qptr->stack1);
			push(&qptr->stack2,val);
		}
	}
	val = pop(&qptr->stack2);
	return val;
}
int main(void)
{
	struct queue *queue = create_queue();
	queue->stack1 = NULL;
	queue->stack2 = NULL;
	int val = 0;
	while (1) {
		printf("Please enter :1 for enqueue opration\n");
		printf("Please enter :2 for dequeue opration\n");
		printf("Please enter :3 for exit opration\n");
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
					enqueue (queue, val);
					break;
				case 2:
					printf("val: %d\n", dequeue(queue));
					break;
				case 3:
					return 0;
					break;
				default :
					printf("Please enter valid operation\n");
			}
		}
	}
	return 0;
}
