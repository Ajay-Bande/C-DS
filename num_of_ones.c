#include<stdio.h>

int main(void)
{
	unsigned char n = 15,i;
	static unsigned char no_of_ones = 0;
	for(i=0; i < 8; i++) {
		if ((n >> i) & 1)
			no_of_ones++;
	}
	printf("no_of_ones: %d\n", no_of_ones);

	return 0;
}
