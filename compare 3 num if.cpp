#include<stdio.h>

int max(int a, int b) {
	if(a>b)return a;
	else return b;
}

int main() 
{
	int x,y,z,max;
	printf("Enter number : ");
	scanf("%d %d %d",&x,&y,&z);
	
	if(x>y && x>z)max = x;
	else if(y>x && y>z)max = y;
	else if(z>y && z>x)max = z;
	else max=z;
	
	printf("Maximum is %d",max);
	return 0;
	}
	



