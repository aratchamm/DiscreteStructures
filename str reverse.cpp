#include<stdio.h> 
#include <ctype.h>

int main() {
	
	char str[50];
	char* ptr;
	char* ltr;
	int i=0;
	char var= ' ';
	
	ptr = str;
	scanf("%[^\n]s",str);
	
	while (*ptr != '\0') {
		if(isspace(*ptr)){
			ltr = ptr;
			while (ptr >= ltr) {
			printf("%c", *ptr);
			ptr--;
			}
			
			i++;	
		}
		ptr++;
	}
	
	
	
	
	
	printf("%d", i);
	
	return 0;
}

