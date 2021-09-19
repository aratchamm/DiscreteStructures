#include<stdio.h>

int main() {
	
	char str[100];
	char* ptr;
	int vowel[5] = {0,0,0,0,0};
	char vowel_char[5] = {'A','E','I','O','U'};
	ptr = str;
	scanf("%[^\n]",str);
	while (*ptr != '\0') {
		if(*ptr=='A' || *ptr=='a')vowel[0]++;
		if(*ptr=='E' || *ptr=='e')vowel[1]++;
		if(*ptr=='I' || *ptr=='i')vowel[2]++;
		if(*ptr=='O' || *ptr=='o')vowel[3]++;
		if(*ptr=='U' || *ptr=='u')vowel[4]++;
		ptr++;
	}
	for (int i=0; i<=4; i++) {
		if (vowel[i]>=1) {
			printf("%c = ",vowel_char[i]);
			printf("%d\n", vowel[i]);
		}
	}
	
	return 0;
} 


