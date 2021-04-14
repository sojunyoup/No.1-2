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
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

