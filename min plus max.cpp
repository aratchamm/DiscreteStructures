#include<stdio.h>

int main(){
	int num[3],x,y;
	int min= 20000000; 
	int max = -20000000;
	for(int i=0; i<3; i++) {
		scanf("%d",&num[i]);
		if (num[i]<=min)min=num[i];
		if (num[i]>=max)max=num[i];
	}
		printf("%d + %d = %d",min,max,min+max);
}
