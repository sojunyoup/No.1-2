#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	float dir = 0;
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

