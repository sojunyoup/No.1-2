#pragma once
#include "Object.h"
class Player : public Object
{
private:
	texture* m_sprite;
	int move;
	float Speed;
	int i = 0, j = 0;
	Vector2 pos;
	D3DLOCKED_RECT lr;
	D3DXCOLOR bgColor;
	Timer* noMove;
	Timer* ItemT;
	Timer* bullet;
	bool isnoMove;
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void Move();
	void FloodMap();
	void PaintMap();
	void Restart();
};

