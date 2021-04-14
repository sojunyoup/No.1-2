#pragma once
#include "Object.h"
class OBullet : public Object
{

public:
	OBullet(const Vector2& dir, int num = 0);
	Vector2 Dir;
	int i = 0, j = 0;
	int Num;
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

