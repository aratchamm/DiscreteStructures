#include<stdio.h>
#include<conio.h>
int main(){
 int num,x=2,y;
 printf("enter number:");
 scanf("%d",&num);
 printf("Factory Result :");
  while(num!=1){
   while(num%x==0){
     num=num/x;
     printf("%d",x);
     if(y<num) {
      printf(" x ");
  }
     }
    
    x++;
    }
   
 return 0; 
  }
