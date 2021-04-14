#pragma once
#include "Object.h"
class Boss : public Object
{
private:
	int speedx;
	int speedy;
	int speedx2;
	int speedy2;
	float size =1;
	int i = 0, j = 0;
	float dir;
	bool L = true, R = true, U = true, D = true;
	Timer* sizeTime;
	bool isBig = true;
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void F();
	void FL();
	void FloodFile(int x, int y);
	void FloodFileQ(int x, int y);
	void SizeTi();
};

