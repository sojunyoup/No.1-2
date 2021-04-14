#pragma once
#include "Object.h"
class DieEffect : public Object
{
private:
	int num;
	float size = 1;
	Vector2 Dir;
	Timer* asd;
public:
	DieEffect(Vector2 dir,int number);
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

