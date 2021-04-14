#pragma once
#include "Object.h"
class ingameUi : public Object
{
private:
	//스테이지
	char nowStage[100000];
	//현재 먹은 땅
	char nowScore[100000];
	//못먹은 땅, 보스 가 먹은땅
	char bossScore[100000];
	//스테이지 남은 시간
	char time[100000];
	//3초 후 타이틀
	char title[100000];
	//엔터 재시작
	char restart[10000] = "-Enter- 재시작";
	//전체 스코어
	char allScore[100000];
	//적 수
	char EnemyCount[100000];
	Timer* timer;
	int my;
	int score;
	int enemy;
	int num = 3;
	Timer* goti;
	bool isF = true;
	bool isF1 = true;
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

