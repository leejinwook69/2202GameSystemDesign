#include "DrawMap.h"
#include "KeyControl.h"


void DrawMap::Init()
{
    system("mode con cols=100 lines=80 | title 겜시디");


    //커서관련 Visible TRUE(보임) FALSE(숨김)
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
    //커서관련 끝
}

void DrawMap::GridDraw(int start_x, int start_y, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        gotoxy(start_x, start_y + y);
        if (y == 0)
        {
            cout << "┌";
            for (int x = 1; x < width - 1; x++)
                cout << "┬";
            cout << "┐";
        }
        else if (y == height - 1)
        {
            cout << "└";
            for (int x = 1; x < width - 1; x++)
                cout << "┴";
            cout << "┘";
        }
        else
        {
            cout << "├";
            for (int x = 1; x < width - 1; x++)
                cout << " ";
            cout << "┤";
        }
    }
    return;
}



int DrawMap::TextDraw(int start_x, int start_y)
{
    KeyControl kc;
    int current_x = start_x;
    int current_y = start_y;

    //본문 출력
    gotoxy(start_x/2, start_y/2);
    cout << " 텍스트 내용1 ";
    gotoxy(start_x / 2, start_y / 2 + 1);
    cout << " 텍스트 내용2 ";
    gotoxy(start_x / 2, start_y / 2 + 2);
    cout << " 텍스트 내용3 ";
    gotoxy(start_x / 2, start_y / 2 + 3);
    cout << " 텍스트 내용4 ";
   

//    gotoxy(start_x / 2, start_y / 2 + n-1 );
//    cout << " 텍스트 내용n ";
////////////////////////////////////////////

    //선택지 출력
    gotoxy(start_x-2, start_y);
    cout << "> ";
    cout << "선택지1";
    gotoxy(start_x, start_y+1);
    cout << "선택지2";
    gotoxy(start_x, start_y+2);
    cout << "선택지3";

//    gotoxy(start_x, start_y+ n-1 );
//    cout << "선택지n";
////////////////////////////////////////////

    //메뉴 이동( w,a,s,d + 스페이스바로 선택)
    while (1)
    {
        switch (kc.KeyInput(_getch()))
        {
            case UP:
            {
                if (current_y > start_y)
                {
                    gotoxy(start_x - 2, current_y);
                    cout << " ";
                    gotoxy(start_x - 2, --current_y);
                    cout << ">";
                }
                break;
            }
            case DOWN:
                if (current_y < start_y+3)
                {
                    gotoxy(start_x - 2, current_y);
                    cout << " ";
                    gotoxy(start_x - 2, ++current_y);
                    cout << ">";
                }
                break;
            case SELECT:
                {
                return current_y - start_y;
                }

        }
    }
}

int DrawMap::MenuDraw(int start_x, int start_y)
{
    KeyControl kc;
    int current_x = start_x;
    int current_y = start_y;

    COLOR(2);
    gotoxy(start_x / 2, start_y / 2);
    cout << "   __   ____  __________  __   __ _______  ____";
    gotoxy(start_x / 2, start_y / 2 + 1);
    cout << "  / /  / __ O/ __/_  __/ /  |/  / _ /_  / / __/";
    gotoxy(start_x / 2, start_y / 2 + 2);
    cout << " / /__/ /_/ /O O  / /   / /|_/ / __ |/ /_/ _/  ";
    gotoxy(start_x / 2, start_y / 2 + 3);
    cout << "/____/O____/___/ /_/   /_/  /_/_/ |_/___/___/  ";

    COLOR(7);

    //메뉴 출력
    gotoxy(start_x - 2, start_y);
    cout << "> ";
    COLOR(2);
    cout << "Start Game";
    gotoxy(start_x, start_y + 1);
    cout << "How To Play";
    gotoxy(start_x, start_y + 2);
    cout << "Option";
    gotoxy(start_x, start_y + 3);
    cout << "Quit Game";
    COLOR(7);
    //

    //메뉴 이동( w,a,s,d + 스페이스바로 선택)
    while (1)
    {
        switch (kc.KeyInput(_getch()))
        {
        case UP:
        {
            if (current_y > start_y)
            {
                gotoxy(start_x - 2, current_y);
                cout << " ";
                gotoxy(start_x - 2, --current_y);
                cout << ">";
            }
            break;
        }
        case DOWN:
            if (current_y < start_y + 3)
            {
                gotoxy(start_x - 2, current_y);
                cout << " ";
                gotoxy(start_x - 2, ++current_y);
                cout << ">";
            }
            break;
        case SELECT:
        {
            return current_y - start_y;
        }

        }
    }
}





void DrawMap::MapDraw(char map[21][21])
{
    system("cls");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (map[i][j] == '0')
                cout << "  ";
            else if (map[i][j] == '1')
                cout << "■";
            else if (map[i][j] == '2')
                cout << "P ";
            else if (map[i][j] == '3')
                cout << "★";
            else if (map[i][j] == '4')
                cout << "! ";
        }
        cout << endl;
    }
}


