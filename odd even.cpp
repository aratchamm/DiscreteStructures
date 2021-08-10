#include <stdio.h>

main(){
	int i = 0;
	int num,loop;
	for(loop=0; loop<4; loop++) {
		printf("Enter number = ");
		scanf("%d",&num);
		if(num%2==0)i++;
	}
	printf("Many of odd number = %d ",i);
	
	}
	
	
