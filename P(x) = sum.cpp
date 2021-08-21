#include<stdio.h>
int  main()
{
  int num,sum,z;
  for (int x=1; x<=10000; x++) {
  	sum = 0;
  	for(int i=1; i<x; i++) {
  	if(x%i==0) {
  		sum = sum + i;
  	}
  }

  if(sum==x) {
  	printf("%d , ",sum);
  	}
  }
  printf("\b\b ");
  
}
