#pragma once
#include "Object.h"
class enemy : public Object
{
private:
	int speedx2;
	int speedy2;
	int i = 0, j = 0;
	float dir;
	bool L = true, R = true, U = true, D = true;
	bool isBig = true;
public:
	enemy(int i);
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void SizeTi();
};

