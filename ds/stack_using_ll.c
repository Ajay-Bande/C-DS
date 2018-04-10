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

struct node *pop(struct node *tptr, struct node **bptr, int *ll_len_ptr)
{
	struct node *temp;
	if (tptr == NULL)
		return NULL;
	else if (*ll_len_ptr == 1) {
		temp = tptr;
		tptr = *bptr = NULL;
		--*ll_len_ptr;
		free(temp);
	} else {
		temp = tptr;
		tptr = tptr ->next;
		--*ll_len_ptr;
		free(temp);
	}
	return tptr;
}

struct node *push(struct node *tptr, struct node **bptr, int *ll_len_ptr, int val)
{
	struct node *temp;
	temp = creat_node(val); 
	if ((*bptr == NULL) && (tptr == NULL)) {
		tptr = *bptr = temp;
		tptr -> val = temp->val;
	}
	else {
		temp->next = tptr;
		tptr = temp;
	}
	++*ll_len_ptr;
	return tptr;	
}

void peek(struct node *tptr)
{
	if(tptr == NULL)
		printf("stack is empty\n");
	else
		printf("val: %d addr:%p\n", tptr->val, tptr->next);
		
}

void display(struct node *tptr)
{
	struct node *trav;
	trav = tptr;
	if(tptr == NULL) {
		printf("stack is empty\n");
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
	struct node *top = NULL;
	struct node *bottom = NULL;
	int val = 0;
	int ll_len = 0;
	while (1) {
		printf("Please enter :1 for push opration\n");
		printf("Please enter :2 for pop opration\n");
		printf("Please enter :3 for peek opration\n");
		printf("Please enter :4 to get the size of stack\n");
		printf("Please enter :5 for display stack opration\n");
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
					top = push(top, &bottom, &ll_len, val);
					break;
				case 2:
					top = pop(top, &bottom, &ll_len);
					if ( top == NULL)
						printf(" stack is Empty\n");
					break;
				case 3:
					peek(top);
					break;
				case 4:
					printf("Size of stack is: %d\n", ll_len);
					break;
				case 5:
					display(top);
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
