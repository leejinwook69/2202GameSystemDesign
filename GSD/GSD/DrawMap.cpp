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



int DrawMap::MenuDraw(int start_x, int start_y)
{
    KeyControl kc;
    int current_x = start_x;
    int current_y = start_y;

    COLOR(2);
    gotoxy(start_x/2, start_y/2);
    cout << " ::::::::     ::::::::    :::::::::  ";
    gotoxy(start_x / 2, start_y / 2+1);
    cout << ":+:    :+:   :+:    :+:   :+:    :+: ";
    gotoxy(start_x / 2, start_y / 2+2);
    cout << "+:+          +:+          +:+    +:+ ";
    gotoxy(start_x / 2, start_y / 2+3);
    cout << ":#:          +#+          +#+    +:+ ";
    gotoxy(start_x / 2, start_y / 2+4);
    cout << "+#+   +#+#   +#+          +#+    +#+ ";
    gotoxy(start_x / 2, start_y / 2+5);
    cout << "#+#    #+#   #+#    #+#   #+#    #+# ";
    gotoxy(start_x / 2, start_y / 2+6);
    cout << " ########     ########    ######### ";

    //메뉴 출력
    gotoxy(start_x-2, start_y);
    cout << "> ";
    COLOR(2);
    cout<<"Start Game";
    gotoxy(start_x, start_y+1);
    cout << "How To Play";
    gotoxy(start_x, start_y+2);
    cout << "Option";
    gotoxy(start_x, start_y+3);
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


void DrawMap::MapDraw(int mapNumber)
{
    char map[21][21];

    switch (mapNumber)
    {
    case 1:
    {
        Map1(map);
        system("cls");
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (map[i][j] == '0')
                    cout << "  ";
                else if (map[i][j] == '1')
                    cout << "■ ";

            }
            cout << endl;
        }
            _getch();
        break;
    }
    default:
        break;
    }
}

void DrawMap::Map1(char map[21][21])
{
    strcpy_s(map[0] , "11111111111111111111");
    strcpy_s(map[1] , "11111111111111111111");
    strcpy_s(map[2] , "11001000000100000011");
    strcpy_s(map[3] , "11001001000100100011");
    strcpy_s(map[4] , "11001001000100100011");
    strcpy_s(map[5] , "11001001000100100011");
    strcpy_s(map[6] , "11001001000100100011");
    strcpy_s(map[7] , "11001001000100100011");
    strcpy_s(map[8] , "11001001000100100011");
    strcpy_s(map[9] , "11001001000100100011");
    strcpy_s(map[10], "11001001000100100011");
    strcpy_s(map[11], "11001001000100100011");
    strcpy_s(map[12], "11001001000100100011");
    strcpy_s(map[13], "11001001000100100011");
    strcpy_s(map[14], "11001001000100100011");
    strcpy_s(map[15], "11001001000100100011");
    strcpy_s(map[16], "11001001000100100011");
    strcpy_s(map[17], "11000001000000100011");
    strcpy_s(map[18], "11111111111111111111");
    strcpy_s(map[19], "11111111111111111111");
}


