#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *head;
static int ll_len = 0;

struct node *creat_node(int val)
{
	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));
	ptr->val =val;
	ptr->next = NULL;
	return ptr;
}

void reverse_ll(void)
{
	struct node *next;
	struct node *prev = NULL;
	struct node *curr = head;
	if(head == NULL) {
		printf(" reversing Linklist is empty\n");
	}
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}
int delete_node_at_position(int pos)
{
	struct node *temp;
	struct node *trav;
	int i;
	printf("ll_len: %d pos:%d \n", ll_len, pos);
	if ( pos > ll_len)
		return -1;
	if ((head != NULL) && (pos == 0)) {
		temp = head;
		head = head->next;
		free(temp);
		ll_len--;
		return 0;
	}
	trav = head;
	for (i=0; i < pos-1; i++)
		trav = trav->next;
	if ((ll_len > 0) && (ll_len == pos)){
		temp = trav->next;
		trav->next = NULL;
		free(temp);
	} else {	
		temp = trav->next;
		trav->next = trav->next->next;
		free(temp);
	}
	ll_len--;
	return 0;
}

int insert_node_at_position(int val, int pos)
{
	struct node *temp;
	struct node *trav;
	int i;
	if( pos > ll_len)
		return -1;
	trav = head;
	temp = creat_node(val); 
	for(i=0; i< pos; i++)
		trav = trav->next;
	temp->next = trav->next;
	trav->next = temp;
	ll_len++;
	return 0;
}

void insert_node_at_first(int val)
{
	struct node *temp;
	temp = creat_node(val); 
	if (head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	ll_len++;	
}

void insert_node_at_last(int val)
{
	struct node *temp;
	struct node *trav;
	temp = creat_node(val); 
	if (head == NULL) {
		head = temp;
	}
	else {
		trav = head;
		while (trav->next != NULL) {
			trav = trav->next;
		}
		trav->next = temp;
	}
	ll_len++;	
}

void display(void)
{
	struct node *trav;
	trav = head;
	if(head == NULL) {
		printf("Linklist is empty\n");
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
	int val = 0, pos = 0,ret = -1;
	while (1) {
	
		printf("Please enter :1 for inser node at first opration\n");
		printf("Please enter :2 for inser node at last opration\n");
		printf("Please enter :3 for inser node at position opration\n");
		printf("Please enter :4 for delete node at position opration\n");
		printf("Please enter :5 reverse the linklist opration\n");
		printf("Please enter :6 for display linklist opration\n");
		printf("Please enter :7 for exit opration\n");
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
					insert_node_at_first(val);
					break;
				case 2:
					printf("Please enter value\n");
					scanf("%d", &val);
					insert_node_at_last(val);
					break;
				case 3:
					printf("Please enter value and position\n");
					scanf("%d %d", &val, &pos);
					ret = insert_node_at_position(val, pos);
					if ( ret == -1)
						printf("add position is larger that link list lenght\n");
					break;
				case 4:
					printf("Please enter node position\n");
					scanf("%d", &pos);
					ret = delete_node_at_position(pos);
					if ( ret == -1)
						printf("delete position is larger that link list lenght\n");
					break;
				case 5:
					reverse_ll();
					break;
				case 6:
					display();
					break;
				case 7:
					return 0;
					break;
				default :
					printf("Please enter valid operation\n");
			}
		}
	}
	return 0;
}
