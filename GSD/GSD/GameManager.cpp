#include "DrawMap.h"
#include "GameManager.h"
#include "KeyControl.h"
#include "Stage2Main.h"
#include "Stage4.h"
#include "Stage5.h"
#include "StoryAscii.h"

void GameManager::GameLoop() {
    char tempMap[21][21];
    if (stage == 1) {
        story.Scene1();
        cin.clear();
        SetMap1(tempMap);
        while (playing == 1) {
            dm.MapDraw(tempMap);
            MovePlayer(tempMap, xpos, ypos);
        }
        playing = 1;
        stage++;
        Sleep(1000);
    }
    if (stage == 2) {
        story.Scene2();
        cin.clear();
        while (1)
        {
            cin.clear();
            if (stage4() == 1)
                break;
        }
        stage++;
        dm.Init();

    }
    if (stage == 3) {
        story.Scene3();
        cin.clear();
        SetMap3(tempMap);
        SetPos();
        while (playing == 1) {
            dm.MapDraw(tempMap);
            MovePlayer(tempMap, xpos, ypos);
        }
        playing = 1;
        stage++;
        Sleep(1000);
    }
    if (stage == 4) {
        story.Scene4();
        cin.clear();

        while (1)
        {
            cin.clear();

            if (stage5() == 1)
                break;
        }
        stage++;
        dm.Init();

    }
    if (stage == 5) {
        story.Scene5();
        cin.clear();

        while (1)
        {
            cin.clear();

            if (stage2() == 1)
                break;
        }
        stage++;
    }
    if (stage == 6) {
        story.Scene6();
        cin.clear();

        SetMap6(tempMap);
        SetPos();
        while (playing == 1) {
            dm.MapDraw(tempMap);
            MovePlayer(tempMap, xpos, ypos);
        }
        playing = 1;
        stage++;
        Sleep(1000);
    }
    if (stage == 7) {
        story.Scene7();
        cin.clear();

        SetMap7(tempMap);
        SetPos();
        while (playing == 1) {
            dm.MapDraw(tempMap);
            MovePlayer(tempMap, xpos, ypos);
        }
        playing = 1;
        Sleep(1000);
    }
    Ending();
};

void GameManager::SetPos() {
    xpos = 0;
    ypos = 18;
}

void GameManager::Ending() {
    cout << "게임끝..";
}

void GameManager::MovePlayer(char map[21][21], int start_x, int start_y) {
    switch (kc.KeyInput(_getch()))
    {
    case UP:
        if ((start_y < 20) && ((map[start_y - 1][start_x] == '0') || (map[start_y - 1][start_x] == '4')))
        {
            if (map[start_y - 1][start_x] == '4')
            {
                if (stage == 1) {
                    
                }
                else if (stage == 3) {
                    
                }
                else if (stage == 6) {
                    
                }
                else if (stage == 7) {
                    
                }
            }
            map[start_y][start_x] = '0';
            map[start_y - 1][start_x] = '2';
            ypos--;
            cout << start_y++;
        }
        break;

    case DOWN:
        if ((0 < start_y) && ((map[start_y + 1][start_x] == '0') || (map[start_y + 1][start_x] == '4')))
        {
            if (map[start_y + 1][start_x] == '4')
            {
                //이벤트처리함수
            }
            map[start_y][start_x] = '0';
            map[start_y + 1][start_x] = '2';
            ypos++;
        }
        break;

    case RIGHT:
        if (map[start_y][start_x + 1] == '3') { // 별을 만날때 (스테이지 클리어)
            cout << "Clear";
            Sleep(1000);
            playing = 0;
            xpos++;
        }
        else if (start_y == 18 && start_x == 0) {
            map[start_y][start_x] = '0';
            map[start_y][start_x + 1] = '2';
            xpos++;
        }
        else if ((start_x < 20) && (map[start_y][start_x + 1] == '0'))
        {
            map[start_y][start_x] = '0';
            map[start_y][start_x + 1] = '2';
            xpos++;
        }
        break;

    case LEFT:
        if ((0 < start_x) && (map[start_y][start_x - 1] == '0'))
        {
            map[start_y][start_x] = '0';
            map[start_y][start_x - 1] = '2';
            xpos--;
        }
        break;
    default:
        break;
    }
}

void GameManager::SetMap1(char map[21][21])
{
    strcpy_s(map[0], "11111111111111111111");
    strcpy_s(map[1], "10000000000000000003");
    strcpy_s(map[2], "10101111111011011111");
    strcpy_s(map[3], "10000000101011010001");
    strcpy_s(map[4], "11111114101011010101");
    strcpy_s(map[5], "10000010101011010101");
    strcpy_s(map[6], "10101110101011010101");
    strcpy_s(map[7], "10100000101011010101");
    strcpy_s(map[8], "10101010101011000101");
    strcpy_s(map[9], "10101010101011111101");
    strcpy_s(map[10], "10101110101000000001");
    strcpy_s(map[11], "10100010101111111111");
    strcpy_s(map[12], "11101010100000010001");
    strcpy_s(map[13], "10100010001011010111");
    strcpy_s(map[14], "10111110011010010001");
    strcpy_s(map[15], "10000011011100100101");
    strcpy_s(map[16], "10111001010001110101");
    strcpy_s(map[17], "10111011011111010101");
    strcpy_s(map[18], "20100000000000000101");
    strcpy_s(map[19], "11111111111111111111");
}

void GameManager::SetMap3(char map[21][21])
{
    strcpy_s(map[0], "11111111111111111111");
    strcpy_s(map[1], "10001000000000010003");
    strcpy_s(map[2], "10101011011111110101");
    strcpy_s(map[3], "10101011010100010101");
    strcpy_s(map[4], "10100001010101010101");
    strcpy_s(map[5], "10011101010101010101");
    strcpy_s(map[6], "11000101014101010101");
    strcpy_s(map[7], "11110111010001000101");
    strcpy_s(map[8], "11010011011011111111");
    strcpy_s(map[9], "11011011011010100001");
    strcpy_s(map[10], "10001011011010111101");
    strcpy_s(map[11], "10111011000010000001");
    strcpy_s(map[12], "10101011111111111101");
    strcpy_s(map[13], "10101000000000001101");
    strcpy_s(map[14], "10101111111111100001");
    strcpy_s(map[15], "10101100000111111001");
    strcpy_s(map[16], "10000001110000000001");
    strcpy_s(map[17], "11111101001111101101");
    strcpy_s(map[18], "20000000000000000001");
    strcpy_s(map[19], "11111111111111111111");
}
void GameManager::SetMap6(char map[21][21])
{
    strcpy_s(map[0], "11111111111111111111");
    strcpy_s(map[1], "10100011111111100003");
    strcpy_s(map[2], "10101001000000001111");
    strcpy_s(map[3], "10001011111101101101");
    strcpy_s(map[4], "10111000010000100101");
    strcpy_s(map[5], "10011111111101110101");
    strcpy_s(map[6], "10110000100001000101");
    strcpy_s(map[7], "10100011111411110101");
    strcpy_s(map[8], "10001000001000011101");
    strcpy_s(map[9], "10111010101111010001");
    strcpy_s(map[10], "10101010110001011101");
    strcpy_s(map[11], "10101010000001000001");
    strcpy_s(map[12], "10101010110101010111");
    strcpy_s(map[13], "10101010010101010001");
    strcpy_s(map[14], "10101011010101010101");
    strcpy_s(map[15], "10100010010101010101");
    strcpy_s(map[16], "10000000000101010101");
    strcpy_s(map[17], "11110001111111110101");
    strcpy_s(map[18], "20000000000000000101");
    strcpy_s(map[19], "11111111111111111111");
}

void GameManager::SetMap7(char map[21][21])
{
    strcpy_s(map[0], "11111111111111111111");
    strcpy_s(map[1], "10000001000100000003");
    strcpy_s(map[2], "11010101011101111101");
    strcpy_s(map[3], "10010101011000001101");
    strcpy_s(map[4], "10110101011010101101");
    strcpy_s(map[5], "10110100011010101101");
    strcpy_s(map[6], "10000111111010101101");
    strcpy_s(map[7], "10110000000010100001");
    strcpy_s(map[8], "10110111111110110111");
    strcpy_s(map[9], "10110100000010110001");
    strcpy_s(map[10], "10110101111010101101");
    strcpy_s(map[11], "10110101111010101111");
    strcpy_s(map[12], "10110001111410000001");
    strcpy_s(map[13], "10110110001011111101");
    strcpy_s(map[14], "10110000101000000101");
    strcpy_s(map[15], "10111111100111111111");
    strcpy_s(map[16], "10010101110000000011");
    strcpy_s(map[17], "11000000011111111001");
    strcpy_s(map[18], "20011110000000000001");
    strcpy_s(map[19], "11111111111111111111");
}