//헤더파일 통합용으로 대부분의 파일에 include 시켜서 씀

//Headers
#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstring>

//Define: KEY
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SELECT 4

//Define : Color
#define COLOR(A) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),A);
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define L_BLUE 9
#define L_GREEN 10
#define L_AQUA 11
#define L_RED 12
#define L_PINK 13
#define L_YELLOW 14
#define B_WHITE 15

using namespace std;
