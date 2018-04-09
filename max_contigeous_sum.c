int ContiguousMaxSum(int entry) {

	int max = a[0];
	int sum = 0;
	unsigned int i = 0;

	for(i = 0 ; i < entry; i++)  {
		sum = sum + a[i];

		if(max < sum) {
			max = sum;
		} else if(max < a[i]){
			max = a[i];
		} else if(sum < 0) {
			sum = 0;
		}
	}	
	return max;
}
