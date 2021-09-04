#include<stdio.h>

int main() {

	double x[10];
	int sum = 0;
	for (int i = 1; i <= 10; i++) {
		if(i==1) {
			printf("Enter %dst People's height : ", i);
		}
		else if(i==2) {
			printf("Enter %dnd People's height : ", i);
		}
		else printf("Enter %dth People's height : ", i);
		scanf("%lf", &x[i]);
		sum = sum + x[i];
	}
	sum = sum/10;
	printf("Average = %d", sum);

	return 0;
}
