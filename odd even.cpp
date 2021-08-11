#include <stdio.h>

main(){
	int num[4],loop,b,i;
	int a=0;
	
		for(i=0; i<4; i++) {
			printf("Enter Number = ");
			scanf("%d",&num[i]);
			
			if(num[i]%2==0){
				a++;
			}
		}

	printf("Many of odd number = %d ",a);
	
	}
