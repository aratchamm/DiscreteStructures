#include <stdio.h>

main(){
	char n[2] [100]; 
	char s[2][100];
	int id[2];

	printf("People 1 \n");
	printf("Enter name = ");
	scanf("%s",&n[0]);
	printf("Enter surname = ");
	scanf("%s",&s[0]);
	printf("Enter id = ");
	scanf("%s",&id[0]);
	printf("\n");
	printf("People 2 \n");
	printf("Enter name = ");
	scanf("%s",&n[1]);
	printf("Enter surname = ");
	scanf("%s",&s[1]);
	printf("Enter id = ");
	scanf("%s",&id[1]);
	printf("\n");
	printf("People 3 \n");
	printf("Enter name = ");
	scanf("%s",&n[2]);
	printf("Enter surname = ");
	scanf("%s",&s[2]);
	printf("Enter id = ");
	scanf("%s",&id[2]);
	printf("\n+-------------+------------+-------------+\n|   %s|    %s|    %d|\n\n",n[0],s[0],id[0]);
	printf("|%s   |%s    |    %d|\n\n", n[1],s[1],id[1]);
	printf("|%s   |    %s|    %d|\n+-------------+------------+-------------+\n", n[2],s[2],id[2]);

	return 0;
	}
	
	
