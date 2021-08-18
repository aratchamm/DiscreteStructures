#include <stdio.h>

main(){
	int z,y,x,q,loop,b,i;
	int a=0;
	
		scanf("%d%d%d%d",&z,&y,&x,&q);
		if(z%2==0)a++;
		if(y%2==0)a++;
		if(x%2==0)a++;
		if(q%2==0)a++;

	printf("Many of even number = %d ",a);
	
	}
