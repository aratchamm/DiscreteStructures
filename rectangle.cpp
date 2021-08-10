#include <stdio.h>

int main(){
	int num,a;
	printf("Enter number: ");
	scanf("%d", &num);
	a=num;
	for (int j=0; j<num; j++) {
			printf("*");
		}
	for (int i=0; i<num; i++) {
		printf("\n*");
		for (int k=0; k<num-2; k++) {
			printf(" ");
		}
		printf("*");
	}
	printf("\n");
	for (int j=0; j<num; j++) {
			printf("*");
		}	
	return 0;	
	
	}
	
