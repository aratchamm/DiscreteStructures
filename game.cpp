#include<stdio.h>
#include<windows.h>
#include<conio.h>

void erase_ship(int x,int y){
	for(int i=0; i<=6; i++) {
		printf("\b \b" );
	}
}

void draw_ship(int x, int y){
	erase_ship(x,y);
	printf(" <-0-> ");
}

void gotoxy(int x, int y){
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void control(int x, int y){
	char ch=' ';
	do {
	if (_kbhit()){
	ch=_getch();
	if(x!=7) {
		if(ch=='a'){erase_ship(x,y); gotoxy(--x,y); draw_ship(x,y);}
	}
	if(x!=80) {
		if(ch=='d') {erase_ship(x,y); gotoxy(++x,y); draw_ship(x,y);}
	}
	if(y!=29) {
		if(ch=='s') {erase_ship(x,y); gotoxy(x,++y); draw_ship(x,y);}
	}
	if(y!=0) {
		if(ch=='w') {erase_ship(x,y); gotoxy(x,--y); draw_ship(x,y);}
	}
	fflush(stdin);
	}
	hidecursor();
	Sleep(500);
	}
	while (ch!='x');
}
int main(){
	int x=7,y=20;
	gotoxy (x,y);
	draw_ship(x,y);
	control(x,y);
	return 0;
}


