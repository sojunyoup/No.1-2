#pragma once
#include "Object.h"
class ScrollMap : public Object
{
private:
	int Num;
	texture* Bg;
	texture* Bg1;
	texture* Bg2;
	float dir = 0;

	float scrool;
	float scrool1;
	float scrool2;
public:
	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

