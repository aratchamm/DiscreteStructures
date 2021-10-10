#include<stdio.h>
int main()
{
	
FILE* fp;
int a, b, sum=0;
fp = fopen("a.txt", "r");

a = 0; b = 0;
fscanf(fp, "%d %d", &a, &b);
sum = a+b;

fclose(fp);

fp = fopen("b.txt", "w");
fprintf(fp,"%d", sum);
fclose(fp);
return 0;

}

