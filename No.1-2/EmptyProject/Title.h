#pragma once
#include "Scene.h"
class Title : public Scene
{
public:
	float dir = 0;
	int numTile = 1;
	Timer* Delay;
	bool isStart;
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};
