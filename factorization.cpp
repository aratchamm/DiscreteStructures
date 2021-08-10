#include <stdio.h>

int main(){
	int num;
	int i=2;
	int a=0;
	printf("Enter number = ");
	scanf("%d",&num);
	while(i<=num) {
		if(num%i==0) {
			printf("%d ",i);
			a++;
			num/=i;
			if(a++ && i<=num) {
				printf("x ");
			}
		}
		else if(num%i!=0)i++;
	}
	
	
	
	return 0;
}
