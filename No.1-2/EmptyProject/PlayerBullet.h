#pragma once
#include "Object.h"
class PlayerBullet : public Object
{
private:
	float r;
	Vector2 dir;
	Timer* i;
	bool tur;

public:
	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

