#include <stdio.h>
#include <math.h>

int main(){
	double x,y,z,s,area,ab;
	printf("Enter triangle length = ");
	scanf("%lf",&x);
	printf("Enter triangle length = ");
	scanf("%lf",&y);
	printf("Enter triangle length = ");
	scanf("%lf",&z);
	s = (x+y+z)/2;
	ab = s*(s-x)*(s-y)*(s-z);
	area = sqrt(ab);
	printf("Area = %.0lf",area);
	
	return 0;
	}
	
	
