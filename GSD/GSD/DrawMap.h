//ȭ�� ��°� ���õ� Ŭ����

#pragma once
#include "HeaderSet.h"

class DrawMap
{
public:

	//�ܼ� ������ cols = width, lines = height, title = title
	void Init();

	/// <summary>
	/// Ŀ���� ���ϴ� ��ġ�� �����ִ� �Լ� 
	/// </summary>
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	}
	int TextDraw(int start_x, int start_y);
	/// <summary>
	/// ȭ�鿡 �׸��带 �׸���
	/// </summary>
	void GridDraw(int start_x, int start_y, int width, int height);

	/// <summary>
	/// ȭ�鿡 �޴��� �׸���
	/// </summary>
	int MenuDraw(int start_x, int start_y);

	/// <summary>
	/// ȭ�鿡 ���� �׸���
	/// </summary>
	void MapDraw(char map[21][21]);

	/// <summary>
	/// ù��° �� ������ �޾ƿ´�
	/// </summary>
	void Map1(char map[21][21]);
	void Map2(char map[21][21]);

};

