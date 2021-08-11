#include <stdio.h>

main(){
	float pA,rA,pB,rB,A_n[3],B_n[3];
	int a;
	int x,y=0;
	printf("Population of A = ");
	scanf("%f",&pA);
	printf("Growth rate (%%) = ");
	scanf("%f",&rA);
	printf("Population of B = ");
	scanf("%f",&pB);
	printf("Growth rate (%%) = ");
	scanf("%f",&rB);
	
	for(int loop=0; loop<4; loop++) {
		for(int i=0; i<4; i++) {
			if(i==0) {
				A_n[i] = pA;
				B_n[i] = pB;
			}
			else if(i!=0) {
				A_n[i] = A_n[i-1]*(rA*0.01) + A_n[i-1] ;
				B_n[i] = B_n[i-1]*(rB*0.01) + B_n[i-1] ;
			}
			//A_n[i] = x; 
			//B_n[i] = y;
			//printf("%d%d",Ay,By);
		}
		printf("year %d, A = %.2f B = %.2f\n",loop,A_n[loop],B_n[loop]);
		a++;
	}
	printf("During = %d Years", a-1);
}
