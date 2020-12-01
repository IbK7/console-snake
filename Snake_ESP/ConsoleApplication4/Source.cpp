#include <stdio.h>
#include <conio.h> 
#include <windows.h> 
#include <stdlib.h>
#include <dos.h>
#include <iostream>
#include <time.h>

BOOL gotoxy(const WORD x, const WORD y);

void Down();
void Right();
void Left();
void Up();
void logic();
void input();
void start();

typedef enum direction { stop = 0, left, right, up, down }; direction dir;
char area[120][30];
int x_end = 100, y_end = 29;
int x_position = 15, y_position = 15;
int snake_length = 4;

void main()
{
	start();
	
	while (1){

		input();
		logic();
	}

	system("pause>nul");
}

void start()
{
	int i, j;
	for (i = 12; i < 16; i++)		//making original snake to start with.
	{
		area[i][15] = '*';
	}

	for (j = 0; j < 30; j++)		//filling the rest of the matrix with blank spances.
	{
		for (i = 0; i < 120; i++)
		{
			if (area[i][j] != '*')
				area[i][j] = ' ';
		}
	}

	for (j = 0; j < 30; j++)			//starting game.
	{
		for (i = 0; i < 120; i++)
		{
			printf("%c", area[i][j]);
		}
	}
}
void Up()
{
	int i,j,k,a=0;

		for (k = snake_length; k > 0; k--)
		{
			area[x_position - k][y_position] = ' ';
			area[x_position + k][y_position] = ' ';
			area[x_position][y_position - a] = '*';
			a++;

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 195000000; m++)
			{
			}
			system("cls");
		}
		while (!kbhit())
		{
		y_position = y_position - snake_length + 1;
		k = y_position;
		for (; k > 0; k--)
		{
			area[x_position][y_position + snake_length - 1] = ' ';
			area[x_position][y_position - 1] = '*';
			a++;
			y_position--;

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 195000000; m++)
			{
			}
			system("cls");
		}
	}

	if (k == 0)
	{
		gotoxy(60, 15);
		printf("GAME OVER");
	}
}

void Down()
{
	int i, j, k, a = 0;
	
		for (k = snake_length; k > 0; k--)
		{
			area[x_position - k][y_position] = ' ';
			area[x_position + k][y_position] = ' ';
			area[x_position][y_position + a] = '*';
			a++;
			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 195000000; m++)
			{
			}
			system("cls");
		}

		while (!kbhit())
		{
			if (k == y_end)
			{
				gotoxy(60, 15);
				printf("GAME OVER");
			}
			y_position = y_position + snake_length - 1;
			k = y_position;

			for (; k < y_end; k++){
			area[x_position][y_position - snake_length + 1] = ' ';
			area[x_position][y_position + 1] = '*';
			y_position++;

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 195000000; m++)
			{
			}
			system("cls");
		}
	}
	

}

void Right()
{
	int i, j, k, a = 0;
	
		for (k = snake_length; k > 0; k--)
		{
			area[x_position - k][y_position] = ' ';
			area[x_position][y_position - k] = ' ';
			area[x_position][y_position + k] = ' ';
			area[x_position + a][y_position] = '*';
			a++;

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 195000000; m++)
			{
			}

			system("cls");
		}


		while (!kbhit())
		{
			x_position = x_position + snake_length - 1;
			k = x_position;
		for (; k < x_end; k++)
		{
			area[x_position - snake_length + 1][y_position] = ' ';
			area[x_position + 1][y_position] = '*';
			x_position++;
	
			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 1500000; m++)
			{
			}

			system("cls");
		}
	}

	if (k == x_end)
	{
		gotoxy(60, 15);
		printf("GAME OVER");
	}
}

void Left()
{
	int i, j, k, a = 0;

		for (k = snake_length; k > 0; k--)
		{
			area[x_position + k][y_position] = ' ';
			area[x_position][y_position - k] = ' ';
			area[x_position][y_position + k] = ' ';
			area[x_position - a][y_position] = '*';
			a--;

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 195000000; m++)
			{
			}

			system("cls");
		}

		while (!kbhit())
		{
			x_position = x_position + snake_length - 1;
			k = x_position;
		for (; k > 0; k--)
		{
			area[x_position + snake_length - 1][y_position] = ' ';
			area[x_position - 1][y_position] = '*';
			x_position--;

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					if (area[i][j] != '*')
						area[i][j] = ' ';
				}
			}

			for (j = 0; j < 30; j++)
			{
				for (i = 0; i < 120; i++)
				{
					printf("%c", area[i][j]);
				}
			}

			for (int m = 0; m < 1500000; m++)
			{
			}

			system("cls");
		}
	}
	if (k == 0)
	{
		gotoxy(60, 15);
		printf("GAME OVER");
	}
}

void input()
{
	if (_kbhit()){
		switch (_getch()){
		case'a':
			dir = left;
			break;
		case's':
			dir = down;
			break;
		case'w':
			dir = up;
			break;
		case'd':
			dir = right;
			break;
		}
	}
}

void logic()
{
	switch (dir){
	case left:
		Left();
		break;
	case right:
		Right();
		break;
	case up:
		Up();
		break;
	case down:
		Down();
		break;
	}
}

BOOL gotoxy(const WORD x, const WORD y)
{
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);     // for goto specific coordinates use goto in code 
}