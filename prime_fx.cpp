#include<stdio.h>

int isPrime(int);
int i,b;
int main() 
{
	int x;
	scanf("%d", &x);
	if (isPrime(x) == 1)
		printf("Prime number");
	else if (isPrime(x) == 2)return 0;
	else
		printf("Not Prime number");
	return 0;
}
int isPrime(int a)
{
	if(a==1)return 0;
	if(a==-99)return 2;
	for(i=2; i<a; i++) {
		if(a%i==0)return 0;
	}
	return 1;
	
}


