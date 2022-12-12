#pragma once
#include "HeaderSet.h"
#include "KeyControl.h"

class GameManager
{
public:
	KeyControl kc;
	DrawMap dm;
	bool playing = 1; // 1 = 스테이지 진입중, 0 = 스테이지 진입 x
	int xpos = 0; // 플레이어 x좌표
	int ypos = 18; // 플레이어 y좌표
	int stage = 1; // 스테이지 
	void GameLoop(); //게임 흐름 제어
	void SetMap1(char[21][21]); //스테이지 1 맵 불러오기
	void SetMap3(char[21][21]); //스테이지 3 맵 불러오기
	void SetMap6(char[21][21]); //스테이지 6 맵 불러오기
	void SetMap7(char[21][21]); //스테이지 7 맵 불러오기
	void MovePlayer(char map[21][21],int,int); // 플레이어의 이동 제어 함수
	void SetPos(); //스테이지가 끝난후 위치 초기화 함수
	void Ending(); // 엔딩 - 미구현
};

