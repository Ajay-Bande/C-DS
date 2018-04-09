#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (void)
{
	char *ptr = "bhagu";
	char *rev_ptr = NULL;
	char *trev_ptr = NULL;
	unsigned int len = strlen(ptr);
	printf("len: %d\n", len);
	trev_ptr = (char *) malloc (len+1);
	rev_ptr = trev_ptr;
	while(len != 0) {
		*trev_ptr = *(ptr + len -1);
		printf(" ptr+len :%c str_rev: %c\n", *(ptr+len-1), *trev_ptr);
		trev_ptr++;
		len--;
	}
	*trev_ptr = '\0';
	printf("str_rev: %s\n", rev_ptr);
	return 0;
}
