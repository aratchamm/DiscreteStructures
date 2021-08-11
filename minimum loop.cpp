#include <stdio.h>

main(){
	int a;
	int min = 2000000000;

	for(int i=0; i<3; i++) {
		printf("input numbers = ");
		scanf("%d",&a);

		if(a<min) {
		min = a;
		}
	}
	
	printf("minimum = %d",min);
	}
