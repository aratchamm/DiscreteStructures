#include<stdio.h>
#include<string.h>


int main() {
	
	FILE* fp;
	fp = fopen("c:/temp/data.txt", "w");
	
	char str[1000];
	char* ptr;
	char ch = '\n';
	ptr = str;
	scanf("%s", ptr);
	fputs(ptr,fp);
	fputc(ch,fp);
	while(*ptr != '.') {
		scanf("%s", ptr);
		fputs(ptr,fp);
		fputc(ch,fp);
	}
	fclose(fp);
	
}
