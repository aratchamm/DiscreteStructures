#include<stdio.h>

int main() {

	int num,n;
	printf("Enter 3-digit number : ");
	scanf("%d",&num);
	
	while(num!=0) {
		n = num%10;
		if (n%2==0)printf("even ");
		else printf("odd ");
		num /= 10;
	}
}
