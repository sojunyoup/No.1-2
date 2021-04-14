#pragma once
#include "Object.h"
class Effect : public Object
{
private:
	int num;
	float size = 1;
public:
	Effect(int number);
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

