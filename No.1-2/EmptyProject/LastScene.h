#pragma once
#include "Scene.h"
class LastScene : public Scene
{
private:
	list<int>ScoreList;
	Timer* bam;
	bool next = false;
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

