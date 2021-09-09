#include<stdio.h>
int main()
{
	char str[50];
	char* ptr;
	ptr = str;
	scanf("%s", str);
	printf("str = %s\n", str);
	
	while(*ptr!='\0') {
		
		if(*ptr!=*(ptr-1)) {
			printf("%c", *ptr);
		}
		ptr++;
	}
	

	return 0;
}

