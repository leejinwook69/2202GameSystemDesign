#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <time.h>
#include "Stage5.h"
#include <windows.h>
#include "Stage2.h"
using namespace std;

bool game5Over = false;
bool game5Clear = false;

class cPlayer
{
public:
    int x, y;
    cPlayer(int width) { x = width / 2; y = 0; }
};
class cLane
{
private:
    deque<bool> cars;
    bool right;
public:
    cLane(int width)
    {
        for (int i = 0; i < width; i++)
            cars.push_front(true);
        right = rand() % 2;
    }
    void Move()
    {
        if (right)
        {
            if (rand() % 10 == 1)
                cars.push_front(true);
            else
                cars.push_front(false);
            cars.pop_back();
        }
        else
        {
            if (rand() % 10 == 1)
                cars.push_back(true);
            else
                cars.push_back(false);
            cars.pop_front();
        }

    }
    bool CheckPos(int pos) { return cars[pos]; }
    void ChangeDirection() { right = !right; }
};
class cGame
{
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    cPlayer* player;
    vector<cLane*> map;
public:
    cGame(int w = 20, int h = 10)
    {
        numberOfLanes = h;
        width = w;
        quit = false;
        for (int i = 0; i < numberOfLanes; i++)
            map.push_back(new cLane(width));
        player = new cPlayer(width);
    }
    ~cGame()
    {
        delete player;
        for (int i = 0; i < map.size(); i++)
        {
            cLane* current = map.back();
            map.pop_back();
            delete current;
        }
    }
    void Draw()
    {
        system("cls");
        for (int i = 0; i < numberOfLanes; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 && (j == 0 || j == width - 1)) cout << "S";
                if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) cout << "F";
                if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1)
                    cout << "#";
                else if (player->x == j && player->y == i)
                    cout << "V";
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "아래로 도착 시 클리어, 장애물에 닿을 경우 실패      이동 : w, a, s, d  다시시작 : q" << endl;
    }
    void Input()
    {
        if (_kbhit())
        {
            char current = _getch();
            if (current == 'a')
                player->x--;
            if (current == 'd')
                player->x++;
            if (current == 'w')
                player->y--;
            if (current == 's')
                player->y++;
            if (current == 'q')
                quit = true;
        }
    }
    void Logic()
    {
        for (int i = 1; i < numberOfLanes - 1; i++)
        {
            if (rand() % 10 == 1)
                map[i]->Move();
            if (map[i]->CheckPos(player->x) && player->y == i)
            {
                game5Over = true;
                quit = true;
                
            }
        }
        if (player->y == numberOfLanes - 1)
        {
            game5Clear = true;
            quit = true;

        }
    }
    void Run()
    {
        game5Clear = false;
        game5Over = false;
        while (!quit)
        {
            Input();
            Draw();
            Logic();
            Sleep(50);
        }
    }
};
int stage5()
{
    srand(time(NULL));
    cGame game(30, 15);
    game.Run();
    
    if (game5Over)
    {
        system("cls");
        char str[] = "GAME OVER !!  다시 시작합니다";
        game_Function(SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2, str, 12);
        Sleep(2000);
        setColor(WHITE);
        return 0;
    }
    if (game5Clear)
    {
        system("cls");
        char str1[] = "Stage 5 Clear !!  ";
        char str2[] = "다음 스테이지로 이동합니다";
        game_Function(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2, str1, 14);
        game_Function(SCREEN_WIDTH / 2 - 6, SCREEN_HEIGHT / 2 + 4, str2, 14);
        setColor(WHITE);
        Sleep(2000);
        return 1;
    }

}