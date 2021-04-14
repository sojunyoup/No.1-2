#pragma once
#include "Object.h"
class AllItem : public Object
{
private:
	int item;
	Timer* iteamCreat;
	int itemNum;
	bool isTrue;
	int sp = 1, su = 1, hp = 3, bu = 1, bu1 = 1, bu2 = 1;
	int i = 0, j = 0;
	Vector2 Ipos;
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

