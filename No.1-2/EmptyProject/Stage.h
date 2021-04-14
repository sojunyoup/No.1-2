#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	float dir = 0;
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

