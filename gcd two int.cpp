#include <stdio.h>

int main(){
	int f,s,i,gcd;
	printf("Enter number : ");
	scanf("%d", &f);
	printf("Enter number : ");
	scanf("%d", &s);
	
	for (i=2; i<=f || i<= s; i++) {
		if(f%i==0 && s%i==0) {
			gcd = i;
		}
	}
	
	printf("Greatest common divisor = %d", gcd);
	
	return 0;	
	
	}
	
