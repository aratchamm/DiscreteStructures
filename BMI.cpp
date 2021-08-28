#include <stdio.h>

main(){
	float w,h,h2;
	printf("Enter weight = ");
	scanf("%f", &w);
	printf("Enter height = ");
	scanf("%f",&h);
	h2 = h/100;
	if(h>=30 && h<=250) {
		printf("BMI = %.1f", w/(h2*h2));
	}
	else if(h>=0 && h <=2.5) {
		printf("BMI = %.1f", w/(h*h));
	}
	return 0;
	} 
