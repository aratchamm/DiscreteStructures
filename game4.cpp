#include <stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25 
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y }; 
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };

char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE); 
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}


int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcolor(int fg, int bg) {
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	}
}

void draw_enemy(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf("*");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

CHAR_INFO consoleBuffer[screen_x * screen_y];

void fill_data_to_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = 'A';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}





int main()
{
	bool play = true;
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	int xMouse = 0;
	int yMouse = 0;
	int xEnemy[20];
	int yEnemy[20];
	int random_enemy_color = 2;
	int enemycount = 0;
	int score = 0;
	int color = 7;


	setConsole(screen_x, screen_y);
	setcursor(0);
	setMode();
	while (play)
	{
		srand(time(NULL));
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);

			for (DWORD i = 0; i < numEventsRead; ++i) {


				while (enemycount < 20) {
					int randX = 0;
					int randY = 0;
					while (randX < 10 || randX >60) {
						randX = rand() % 100;
					}
					xEnemy[enemycount] = randX; randX = 0;
					while (randY < 1 || randY > 20) {
						randY = (rand() % 100);
					}
					yEnemy[enemycount] = randY; randY = 0;
					
					draw_enemy(xEnemy[enemycount], yEnemy[enemycount]);
					enemycount++;
				
				}
				
				if (score == 10) {
						gotoxy(0, 0);
						for (int loop = 0; loop <= 25; loop++) {
							setcolor(7, 0);
							printf("                                                                                                                       ");
							printf("\n");
						}
						gotoxy(0, 0);
						return 0;
					}

				for (int l = 0; l < 20; l++) {

						if (xEnemy[l] == xMouse - 1 && yEnemy[l] == yMouse) {
							score++;
							enemycount--;
				
							printf(" ");
						}


						else if (xEnemy[l] == xMouse - 2 && yEnemy[l] == yMouse) {
						score++;
						enemycount--;
						xEnemy[l], yEnemy[l] = 0;
			
						printf(" ");
					} 

						else if (xEnemy[l] == xMouse && yEnemy[l] == yMouse) {
						score++;
						enemycount--;
						xEnemy[l], yEnemy[l] = 0;
				
						printf(" ");
					} 

						else if (xEnemy[l] == xMouse + 1 && yEnemy[l] == yMouse) {
						score++;
						enemycount--;
						xEnemy[l], yEnemy[l] = 0;
					
						printf(" ");
					} 

						else if (xEnemy[l] == xMouse + 2 && yEnemy[l] == yMouse) {
						score++;
						enemycount--;
						xEnemy[l], yEnemy[l] = 0;
				
						printf(" ");
					} 

					}

				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true) {


					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						gotoxy(0, 0);
						for (int loop = 0; loop <= 25; loop++) {
							setcolor(7, 0);
							printf("                                                                                                                       ");
							printf("\n");
						}
						gotoxy(0, 0);
						play = false;
					}

					else if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == 'C') {

						random_enemy_color = (rand() % 5) + 10;
						setcolor(random_enemy_color, 0);
						color = random_enemy_color;
						gotoxy(xMouse - 2, yMouse);
						printf("<=0=>");

					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
						random_enemy_color = (rand() % 5) + 10;
						setcolor(random_enemy_color, 0);
						color = random_enemy_color;

					}

					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {

						if (xMouse != posx || yMouse != posy) {
							if (posx > 1 && posx < 78) {
								gotoxy(xMouse - 2, yMouse);
								printf("     ");
							}
						}


						if (posx > 1 && posx < 78) {
							gotoxy(posx - 2, posy);
							setcolor(color, 0);
							xMouse = posx;
							yMouse = posy;
							printf("<=0=>");
						}
						
						Sleep(10);

					}

					

				}


			}

			delete[]eventBuffer;
		}
		Sleep(100);
	}
	return 0;
}
