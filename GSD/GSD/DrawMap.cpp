#include "DrawMap.h"


DrawMap::DrawMap()
{

}

void DrawMap::Init()
{
    system("mode con cols=100 lines=80 | title °×½Ãµð");
}

void DrawMap::GridDraw(int start_x, int start_y, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        gotoxy(start_x, start_y + y);
        if (y == 0)
        {
            cout << "¦£";
            for (int x = 1; x < width - 1; x++)
                cout << "¦¨";
            cout << "¦¤";
        }
        else if (y == height - 1)
        {
            cout << "¦¦";
            for (int x = 1; x < width - 1; x++)
                cout << "¦ª";
            cout << "¦¥";
        }
        else
        {
            cout << "¦§";
            for (int x = 1; x < width - 1; x++)
                cout << " ";
            cout << "¦©";
        }
    }
    return;
}



void DrawMap::MenuDraw(int start_x, int start_y)
{
    gotoxy(start_x, start_y);
    cout << "Start Game";
    gotoxy(start_x, start_y+1);
    cout << "How To Play";
    gotoxy(start_x, start_y+2);
    cout << "Option";
    gotoxy(start_x, start_y+3);
    cout << "Quit Game";

}

DrawMap::~DrawMap()
{
}