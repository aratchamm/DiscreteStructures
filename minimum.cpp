#include <stdio.h>

main(){
	int a,b,c,min;
	scanf("%d%d%d",&a,&b,&c);
	
	if(a<b && a<c) {min = a;}

	else if(b<a && b<c) {min = b;}

	else if(c<b && c<b){min = c;}

	
	printf("minimum = %d", min);

	return 0;
	}
	
	
