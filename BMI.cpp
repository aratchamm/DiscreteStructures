#include <stdio.h>

main(){
	float w,h;
	printf("Enter weight = ");
	scanf("%f", &w);
	printf("Enter height = ");
	scanf("%f",&h);
	printf("BMI = %.1f", w/(h*h));

	return 0;
	}
	
	
