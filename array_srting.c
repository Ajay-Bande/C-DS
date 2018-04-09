#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct arr_str {
	char name[32];
	int val;
};

int main(void)
{
	struct arr_str *ptr;
	ptr = (struct arr_str *) malloc(sizeof(struct arr_str));
	if (ptr == NULL) {
		printf("error in malloc\n");
		return -1;
	}
	strcpy(ptr->name, "Virtual-media-controller");
	printf("%s\n", ptr->name);

	return 0;
}
