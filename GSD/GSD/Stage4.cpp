#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Stage4.h"
#include "Stage2.h"
using namespace std;
bool gameOver;
bool gameClear;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;


void Setup()
{
	gameOver = false;
	gameClear = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls"); //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << "/50              이동 : w, a, s, d  다시하기 : x " << endl;
}


void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}


void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
int stage4()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(100); //sleep(10);
		if (score >= 50)
		{
			gameClear = true;
			break;
		}
	}
	if (gameOver)
	{
		system("cls");
		char str[] = "GAME OVER !!  다시 시작합니다";
		game_Function(SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2, str, 12);
		Sleep(2000);
		setColor(WHITE);
		return 0;
	}
	if (gameClear)
	{
		system("cls");
		char str1[] = "Stage Clear !!  ";
		char str2[] = "다음 스테이지로 이동합니다";
		game_Function(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2, str1, 14);
		game_Function(SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2 + 4, str2, 14);
		setColor(WHITE);
		Sleep(2000);
		return 1;
	}
}