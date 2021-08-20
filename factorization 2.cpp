#include<stdio.h>
int  main()
{
  int num,sum;
  scanf("%d",&num);
  printf("P(%d) = ", num);
  for(int i=1; i<num; i++) {
  	if(num%i==0) {
  		printf(" %d",i);
  		printf(" +");
  		sum = sum + i;
  	}
  }
  printf("\b");
  printf("= %d",sum);
}
