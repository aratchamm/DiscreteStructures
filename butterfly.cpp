#include<stdio.h>
int main() {
	int num,middle,row,space,sym;
	scanf("%d",&num);
	for(row=num; row>= 1; row--) {
		for(sym=num-1; sym>=row; sym--)printf("*");
		for(space=1; space<=(2*row)-1; space++)printf(" ");
		for(sym=num-1; sym>=row; sym--)printf("*");
		printf("\n");
	}
		
	for(middle=1; middle<=num+(num-1); middle++)printf("*");
	printf("\n");
	
	for(row=1; row<= num; row++) {
	for(sym=1; sym<= num-row; sym++)printf("*");
	for(space=1; space<= (2*row)-1; space++)printf(" ");
	for(sym=1; sym<= num-row; sym++)printf("*");
	printf("\n");
}
	
	 
			
	return 0;
} 


