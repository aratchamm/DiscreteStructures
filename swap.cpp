#include<stdio.h>

void swap(int* x, int* y) {

	int A, B;
	A = *x;
	B = *y;

	*x = B; *y = A;

}


int main() {

	int a, b;

	scanf_s("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);

}

