#pragma once
#include "Scene.h"
class StageTwo : public Scene
{
private:
	float dir;
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};
