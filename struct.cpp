#include<stdio.h>
#include<string.h>

int main() {
	
	FILE* fp;
	
	struct player {
		
		char name[50];
		int score;
		int level;
	};
	
	player p[5];
	
	for (int i=0; i<5; i++) {
		printf("Player %d\n\n",i+1);
		printf("Name = ");
		scanf("%s", p[i].name);
		printf("Score = ");
		scanf("%d", &p[i].score);
		printf("Level = ");
		scanf("%d", &p[i].level);
		printf("\n");
	}
	
	fp = fopen("Struct Player.txt", "w");
		for (int i=0; i<5; i++) {
		fprintf(fp, "Player %d\t", i+1);
		fprintf(fp,"name = %s\t", p[i].name);
		fprintf(fp,"score = %d\t", p[i].score);
		fprintf(fp,"level = %d\n", p[i].level);
	}

	fclose(fp);
	
	return 0;
}





