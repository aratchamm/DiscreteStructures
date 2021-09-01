#include<stdio.h>

int isPrime(int);
int i,b;
int main() 
{
	int x;
	scanf("%d", &x);
	
	if (x==1 || x==2) {
		printf("Not Prime number");
	}
	else if (x==-99) {
		return 0;
	}
	else for(i=2; i<x; i++) {
		if(x%i==0) {
			printf("Not Prime number");break;
		}
		else printf("Prime number");break;
	}

	return 0;
}

