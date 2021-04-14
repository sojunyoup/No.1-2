#pragma once
#include "Object.h"
class Item : public Object
{
private:
	int Num;
	int i = 0, j = 0;

public:
	Item(int num);
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

