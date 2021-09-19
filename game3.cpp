#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h> 

char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
void setcolor(int fg, int bg) {
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	}
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void runBullet(int X, int Y, int i) {
	int x[5], y[5];
	x[i] = X; y[i] = Y;
	setcolor(10, 0);
	gotoxy(x[i] + 3, y[i] - 1);
	printf("A");


}
void eraseBullet(int X, int Y, int i) {
	int x[5] = {}, y[5] = {};
	x[i] = X; y[i] = Y;
	setcolor(0, 0);
	gotoxy(x[i] + 3, y[i] - 1);
	printf(" ");

}

void shootBullet(int X, int Y, int M, int i) {
	int x[5] = {}, y[5] = {}, m[5] = {};
	x[i] = X; y[i] = Y; m[i] = M;
	if (m[i] != y[i]) {
		eraseBullet(x[i], y[i] + 1, i);
	}

	if (y[i] != 0) { runBullet(x[i], y[i], i); }

}
void draw_ship(int x, int y)
{
	int X;
	setcolor(14, 0);
	if (x < 0) { X = 0; }
	else X = x;
	gotoxy(X, y);
	if (x < 0) {
		printf("l=0=l ");
		x = 0;
	}
	else {
		printf(" l=0=l ");
	}


}

void draw_Enemy(int X, int Y) {

	gotoxy(X, Y);
	setcolor(5, 0);
	printf("*");

}

void eraseThing(int x, int y) {
	gotoxy(x, y);
	printf(" ");
}

void erase_ship(int x, int y)
{
	int X;
	setcolor(0, 0);
	if (x < 0) { X = 0; }
	else X = x;
	gotoxy(X, y);
	if (x < 0) {
		printf("       ");
		x = 0;
	}
	else {
		printf("       ");
	}
}

int main() {

	int x = 38, y = 29, i, j, Dir = 0, Shoot[5] = { 0,0,0,0,0 }, Xb[5], Yb[5], m[5], enemycount=0;
	unsigned int score = 0;
	int xEnemy, yEnemy, randnum = 0;
	char ch = ' ';

	setcursor(0);
	srand(time(NULL));
	draw_ship(x, y);
	

	do {

		while (enemycount < 20) {
			while (randnum < 10 || randnum > 70) {
				randnum = rand();
			}
			xEnemy = randnum; randnum = 0;
			while (randnum < 2 || randnum >5) {
				randnum = rand();
			}
			yEnemy = randnum;

			draw_Enemy(xEnemy, yEnemy);
			enemycount++;
		}
		gotoxy(1, 1);
		setcolor(9, 0);
		printf("SCORE = %d", score);

		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x >= 0) {
				Dir = -1;
				erase_ship(x, y);		draw_ship(--x, y);
			}
			if (ch == 'd' && x <= 73) {

				Dir = 1;
				erase_ship(x, y);		draw_ship(++x, y);
			}
			if (ch == 's') {
				if (y <= 28) { erase_ship(x, y);		draw_ship(x, ++y); }
				Dir = 0;
			}
			if (ch == ' ') {
				for (i = 0; i <= 4; i++) {
					if (Shoot[i] == 0) {
						Beep(2000, 10);  Shoot[i] = 1;  Xb[i] = x; Yb[i] = y; m[i] = y; goto aa;
					}

				}

			}

		aa:fflush(stdin);
		}


		if (Dir == 0) {
			erase_ship(x, y);		draw_ship(x, y);  Sleep(50);
		}
		else if (Dir == -1) {
			Sleep(50);
			erase_ship(x, y);		draw_ship(--x, y);
		}
		else if (Dir == 1) {
			Sleep(50);
			erase_ship(x, y);		draw_ship(++x, y);
		}
		if (x == 0 || x == 73) {
			if (Dir == -1) {
				Sleep(50);  erase_ship(x, y);		draw_ship(--x, y);
			}
			else if (Dir == 1) {
				Sleep(50);  erase_ship(x, y);		draw_ship(++x, y);
			}
			Dir = 0;
		}
		for (i = 0; i <= 4; i++)
		{
			if (Shoot[i] == 1)
			{
				if (Yb[i] <= 0) { Shoot[i] = 0; }
				shootBullet(Xb[i], Yb[i], m[i], i);
				Yb[i]--;
				if (cursor(Xb[i]+3 , Yb[i] - 1) == '*') {
					Beep(5000, 10);
					eraseThing(Xb[i]+3, Yb[i]-1);
					eraseBullet(Xb[i], Yb[i] + 1, i);
					Shoot[i] = 0;
					Yb[i] = 0;
					enemycount--;
					score++;
				}
			}
		}

		Sleep(50);
	} while (ch != 'x');

	return 0;
}
