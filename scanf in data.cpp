#include<stdio.h>
#include<string.h>

int main() {
	
	FILE* fp;
	fp = fopen("c:/temp/data.txt", "w");
	
	char str[1000];
	char* ptr;
	ptr = str;
	scanf("%s", ptr);
	fprintf(fp, "%s\n", ptr);
	while(*ptr != '.') {
		scanf("%s", ptr);
		fprintf(fp, "%s\n", ptr);
	}
	fclose(fp);
	
}
