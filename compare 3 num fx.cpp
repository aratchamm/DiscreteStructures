#include<stdio.h>

int max(int a, int b) {
	if(a>b)return a;
	else return b;
}

int main() 
{
	int x,y,z;
	printf("Enter number : ");
	scanf("%d %d %d",&x,&y,&z);
	printf("Maximum is %d", max(max(x,y),max(y,z)));
	return 0;
	}
	



