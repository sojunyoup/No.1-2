#pragma once
#include"singleton.h"
#include "Boss.h"
#include "Booss.h"
class GameManager : public singleton<GameManager>
{
public:
	Boss* boss;
	Booss* booss;
	GameManager();
	~GameManager();
	Vector2 EnemyPos;
	float EnemyR;
	int ashp = 2;
	Vector2 EnemyPos1;
	float EnemyR1;
	int PlayerHp = 5;
	bool isDie = false;
	bool isNoMove = false;
	float GameScore = 0;
	float AllScore = 0;
	int nowStageNum = 0;
	int BossScore = 0;
	int nowTime = 180;
	int EnemyNum;
	bool isDieEnemy;
	texture* m_sprite;
	Vector2 dir123;
	int bulletgoing = 0;
	bool isPaintMap = false;
	int PlayerSpeed = 10;
	int map[WINSIZEX / 10][WINSIZEY / 10] = { 0, };
	int Bosmap[WINSIZEX / 10][WINSIZEY / 10] = { 0, };
	int bulletP;
	bool isSuper = false;
	bool isBullet = false;
	void Update();
	void Render();
	void LineDelete();
	void PlayerDie();
	void Restartp();
};

#define GAME GameManager::GetInstance()