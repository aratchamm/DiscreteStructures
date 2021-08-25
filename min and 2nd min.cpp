#include<stdio.h>

int main(){
	int num[3],x,y;
	int min= 20000000; 
	int min2 = 20000000;
	for(int i=0; i<3; i++) {
		scanf("%d",&num[i]);
		if (num[i] <= min) {
			if (min < min2) {
				min2 = min;
			}
			min = num[i];
		}
		if (num[i] <= min2 && num[i]!= min) {
			min2 = num[i];
		}
	}
		printf("min = %d, 2nd min = %d\n",min,min2);
}
