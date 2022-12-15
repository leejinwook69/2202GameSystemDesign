#pragma once
#include "HeaderSet.h"
#include "KeyControl.h"
#include "StoryAscii.h"

class GameManager
{
public:
	KeyControl kc;
	DrawMap dm;
	StoryAscii story;
	bool playing = 1; // 1 = �������� ������, 0 = �������� ���� x
	int xpos = 0; // �÷��̾� x��ǥ
	int ypos = 18; // �÷��̾� y��ǥ
	int stage = 1; // �������� 
	void GameLoop(); //���� �帧 ����
	void SetMap1(char[21][21]); //�������� 1 �� �ҷ�����
	void SetMap3(char[21][21]); //�������� 3 �� �ҷ�����
	void SetMap6(char[21][21]); //�������� 6 �� �ҷ�����
	void SetMap7(char[21][21]); //�������� 7 �� �ҷ�����
	void MovePlayer(char map[21][21], int, int); // �÷��̾��� �̵� ���� �Լ�
	void SetPos(); //���������� ������ ��ġ �ʱ�ȭ �Լ�
	void Ending(); // ���� - �̱���
};