#include<stdio.h>

int main() {
	
	char str[100];
	char* ptr;
	int vowel[5] = {0,0,0,0,0};
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
	
	if (vowel[0]>=1)printf("a = %d\n", vowel[0]);
	if (vowel[1]>=1)printf("e = %d\n", vowel[1]);
	if (vowel[2]>=1)printf("i = %d\n", vowel[2]);
	if (vowel[3]>=1)printf("o = %d\n", vowel[3]);
	if (vowel[4]>=1)printf("u = %d", vowel[4]);
}
