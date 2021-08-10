#include <stdio.h>

main(){
	int a,b,c,min;
	printf("Enter number = ");
	scanf("%d",&a);
	printf("Enter number = ");
	scanf("%d",&b);
	printf("Enter number = ");
	scanf("%d",&c);
	
	if(a<b && a<c) {min = a;}

	else if(b<a && b<c) {min = b;}

	else if(c<b && c<b){min = c;}

	
	printf("Minimum = %d", min);

	return 0;
	}
	
	
