#include <stdio.h>

main(){
	int x1,y1,x2,y2,x1_n,x2_n,y1n,y2n;
	//x11 = y1*0.01*x1;
	//x21 = y2*0.01*x2;
	
	printf("Population of A = ");
	scanf("%d", &x1);
	printf("Growth rate (%%) = ");
	scanf("%d", &y1);
	printf("Population of B = ");
	scanf("%d", &x2);
	printf("Growth rate (%%) = ");
	scanf("%d", &y2);
	y1n = y1*0.01;
	y2n = y2*0.01;
	printf("year 0,  A = %d ,B = %d\n",x1,x2); 
	
	for(int i =0; i<4; i++) {
		x1_n = (y1n*x1) + x1;
		x2_n = (y2n*x2) + x2;
		printf("year %d,  A = %d ,B = %d\n",i,x1_n,x2_n);
	}
	
	//printf("year 1,  A = %d ,B = %d\n",x1_n,x2_n);
	//printf("year 2,  A = %d ,B = %d\n",x1_n,x2_n);
	//printf("year 2,  A = %d ,B = %d\n",x1*y1*y1/10000, x2*y2*y2/10000);
	//printf("year 3,  A = %d ,B = %d\n",x1*y1*y1*y1/1000000, x2*y2*y2*y2/1000000);
	
	}
	
	//a = (10000 x 0.3) + 10000
	//0.3
	
	
