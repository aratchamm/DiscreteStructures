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


int Move(int x, int y) {

	int i = 1;
	int j = 0;
	int k = 0;
	int* a = &x;
	int* b = &y;

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

				if (k == 0) {
					int* a = &x;
					int* b = &y;
					k = 1;
				}

				else if (k == 1) {

					setcolor(7, 0);
					if (*b > 0 || *b < 30) {
						gotoxy(*a, *b); draw_bullet(*a, -- * b); erase_ship(*a, *b);
					}

					if (*b <= 0 || *b >= 30) {
						erase_ship(*a, *b); j = 0; k = 0;
					}

					Sleep(500);

				}


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

				if (k == 0) {
					int* a = &x;
					int* b = &y;
					k = 1;
				}

				else if (k == 1) {

					setcolor(7, 0);
					if (*b > 0 || *b < 30) {
						gotoxy(*a, *b); draw_bullet(*a, -- * b); erase_ship(*a, *b);
					}

					if (*b <= 0 || *b >= 30) {
						erase_ship(*a, *b); j = 0; k = 0;
					}

					Sleep(500);

				}


			}

			Sleep(500);

			if (j == 1) {

				if (k == 0) {
					int* a = &x;
					int* b = &y;
					k = 1;
				}

				else if (k == 1) {

					setcolor(7, 0);
					if (*b > 0 || *b < 30) {
						gotoxy(*a, *b); draw_bullet(*a, -- * b); erase_ship(*a, *b);
					}

					if (*b <= 0 || *b >= 30) {
						erase_ship(*a, *b); j = 0; k = 0;
					}

					Sleep(500);

				}
				

			}

		}

		while (i == 4) {

			if (j == 1) {

				int* a = &x;
				int* b = &y;

				setcolor(7, 0);
				if (*b > 0 || *b < 30) {
					gotoxy(*a, *b); draw_bullet(*a, --* b);
				}

				if (*b <= 0 || *b >= 30) {
					erase_ship(*a, *b); j = 0;
				}

				Sleep(500);

			}
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

