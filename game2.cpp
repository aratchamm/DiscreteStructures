#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void erase_ship(int x, int y) {
	for (int i = 0; i <= 6; i++)printf("\b \b");

}

void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}

void draw_bullet(int x, int y)
{
	gotoxy(x, y); printf("   |   ");
}

int bullet(int a, int b) {

	int i = 0;

	if (i == 0) {
		gotoxy(a, --b);
		i = 1;
	}

	setcolor(7, 0);
	do {
		erase_ship(a, b); gotoxy(a, ----b); draw_bullet(a, b); Sleep(500);
	} while (b >= 1);

	if (b <= 1) {
		erase_ship(a, b);
	}

	return 0;
}


int Move(int x, int y) {

	int i = 1;
	int j = 0;

	char ch = ' ';
	do {
		if (_kbhit()) {
			ch = _getch();

			if (x != 0 && ch == 'a')i = 2;
			else if (x != 72 && ch == 'd')i = 3;
			else if (ch == 's')i = 4;
			else if (ch == 'd')j = 1;

			fflush(stdin);
		}
		Sleep(500);

		while (i == 2) {

			if (j == 1) {
				bullet(x, y);
				gotoxy(++x, y);
				erase_ship(x, y);
				j = 0;
			}

			if (x != 0)setcolor(7, 0); erase_ship(x, y); setcolor(7, 0); gotoxy(--x, y); setcolor(2, 4); draw_ship(x, y);
			if (x == 0)Move(x, y);
			if (_kbhit()) {
				ch = _getch();
				if (ch == 's')i = 4;
				else if (ch == 'd')i = 3;
				else if (ch == ' ')j = 1;
				else if (ch == 'x')return 0;
				fflush(stdin);
			}

			Sleep(300);

		}

		while (i == 3) {

			if (j == 1) {
				bullet(x, y);
				gotoxy(--x, y);
				erase_ship(x, y);
				j = 0;
			}


			if (x != 72)setcolor(7, 0); erase_ship(x, y); setcolor(7, 0); gotoxy(++x, y); setcolor(2, 4); draw_ship(x, y);
			if (x == 72)Move(x, y);
			if (_kbhit()) {
				ch = _getch();
				if (ch == 's')i = 4;
				else if (ch == 'a')i = 2;
				else if (ch == 'x')return 0;
				else if (ch == ' ')j = 1;
				fflush(stdin);
			}

			Sleep(500);

		}

		while (i == 4) {
			setcolor(7, 0); erase_ship(x, y); setcolor(7, 0); gotoxy(x, y); setcolor(2, 4); draw_ship(x, y); i = 0;
		}

	} while (ch != 'x');

	return 0;
}



int main() {
	int x = 60, y = 20;
	int* a = &x;
	int* b = &y;
	setcursor(0);
	gotoxy(x, y);
	Move(x, y);
	setcolor(7, 0);
}

