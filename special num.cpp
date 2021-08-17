#include<stdio.h>
int main() {
	int n,x,sum,y;
	scanf("%d",&n);
	
	while(n>10) {
		x = n/10;
		y = n%10;
		sum = x+y;
		n = sum;
	}
	printf("%d",sum);
			
	return 0;
} 


