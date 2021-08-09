#include <stdio.h>

main(){
	char n[2] [100]; 
	char s[2][100];
	int id[2];

	scanf("%s%s%d",&n[0],&s[0],&id[0]);
	scanf("%s%s%d",&n[1],&s[1],&id[1]);
	scanf("%s%s%d",&n[2],&s[2],&id[2]);
	printf("+-------------+------------+-------------+\n|   %s|    %s|    %d|\n\n",n[0],s[0],id[0]);
	printf("|%s   |%s    |    %d|\n\n", n[1],s[1],id[1]);
	printf("|%s   |    %s|    %d|\n+-------------+------------+-------------+\n", n[2],s[2],id[2]);

	return 0;
	}
	
	
