#include<stdio.h>

int main() {
	
	char str[50];
	float credits;
	float grade;
	printf("Subject = ");
	scanf("%s", str);
	printf("Credits = ");
	scanf("%f", &credits);
	printf("Grade = ");
	scanf("%f", &grade);
	
	printf("Subject = %s | Credits = %.2f | Grade = %.2f",str,credits,grade);
	
}
