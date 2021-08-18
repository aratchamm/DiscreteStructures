#include <stdio.h>
main(){
	int a,b,c,min,min2;
	scanf("%d%d%d",&a,&b,&c);
	if(a<=b && a<=c)printf("%d is minimum",a);
	else if(b<=a && b<=c)printf("%d is minimum",b);
	else if(c<=b && c<=a)printf("%d is minimum",c);
	printf("\n");
	if(a<=b && a>=c)printf("%d is 2nd minimum",a);
	else if(b<=a && b>=c)printf("%d is 2nd minimum",b);
	else if(c<=b && c>=a)printf("%d is 2nd minimum",c);
	
	
	}
