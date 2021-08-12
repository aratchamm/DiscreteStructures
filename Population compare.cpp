#include <stdio.h>

main(){
	float pA,rA,pB,rB,A_n[100],B_n[100];
	int a;
	int x,y;
	int Ay,By;
	printf("Population of A = ");
	scanf("%f",&pA);
	printf("Growth rate (%%) = ");
	scanf("%f",&rA);
	printf("Population of B = ");
	scanf("%f",&pB);
	printf("Growth rate (%%) = ");
	scanf("%f",&rB);
	
	x = pA; 
	y = pB;
	
	while(x<=y) {
		for(int i=0; i<100; i++) {
			if(i==0) {
				A_n[i] = pA;
				B_n[i] = pB;
			}
			else if(i!=0) {
				A_n[i] = A_n[i-1]*(rA*0.01) + A_n[i-1] ;
				B_n[i] = B_n[i-1]*(rB*0.01) + B_n[i-1] ;
			}
			x = A_n[i]; 
			y = B_n[i];
		
		printf("year %d, A = %.2f B = %.2f\n",a,A_n[i],B_n[i]);
		a++;
		if(A_n[i]>B_n[i])break;
	}
	printf("During = %d Years", a-1);
	}
}
	
