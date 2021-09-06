#include<stdio.h> 

int main() {

	int  num, i, j, k, l;
	int m=1;
	scanf("%d", &num);
	k = num;

	for (i = 0; i < num - 1; i++) {
		for (l = 0; l < i; l++)printf(" ");
		for (j = k + k - 1; j >= 1; j--) {
			printf("*");
		}
		printf("\n");
		k -= 1;
	}
	for (i = num - 1; i >= 1; i--)printf(" ");
	printf("*\n");
	k = num;
	for (i = num-1; i>=1; i--) {
		for (l = i-1; l >0; l--)printf(" ");
		for (j = 1; j<=m+2; j++) {
			printf("*");
		}
		printf("\n");
		m += 2;
	}


}

