#pragma once
#include "Scene.h"
class ScoreScene : public Scene
{
private:
	Timer* Delay;
	Timer* plueSpeed;
	char now[100000];
	char all[100000];
	char scoreTitle[10000] = "-SCORE-";
	int nowNum;
	int allNum;
	bool isStart = false;
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

