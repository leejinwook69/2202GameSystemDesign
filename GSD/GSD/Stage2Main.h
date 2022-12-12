#pragma once
void Buffer_Flip(void);
void Buffer_Clear(void);
void Sprite_Draw(int iX, int iY, wchar_t chSprite);
void Buffer_Print(int j, int i, char c);
void Bullet_Shoot();
void Charector_Move();
void Enemy_Create(); //적 생성
void Enemy_Attack(); //적 공격
void Enemy_Move(); //적 움직임
void ShowOption(); //상태창 표시
void init_Stage(); //스테이지 로드
void init_Game(); //게임 로드

//Main 함수 시작
int stage2(void);