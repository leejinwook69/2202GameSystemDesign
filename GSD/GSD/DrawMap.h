//화면 출력과 관련된 클래스

#pragma once
#include "HeaderSet.h"

class DrawMap
{
public:

	//콘솔 생성용 cols = width, lines = height, title = title
	void Init();

	/// <summary>
	/// 커서를 원하는 위치로 보내주는 함수 
	/// </summary>
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	}
	int TextDraw(int start_x, int start_y);
	/// <summary>
	/// 화면에 그리드를 그린다
	/// </summary>
	void GridDraw(int start_x, int start_y, int width, int height);

	/// <summary>
	/// 화면에 메뉴를 그린다
	/// </summary>
	int MenuDraw(int start_x, int start_y);

	/// <summary>
	/// 화면에 맵을 그린다
	/// </summary>
	void MapDraw(char map[21][21]);

	/// <summary>
	/// 첫번째 맵 정보를 받아온다
	/// </summary>
	void Map1(char map[21][21]);
	void Map2(char map[21][21]);

};

