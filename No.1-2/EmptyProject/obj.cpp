#include "DXUT.h"
#include "obj.h"
#include "Effect.h"
void obj::Init()
{
}

void obj::Update()
{
	Move();
	OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
}

void obj::Render()
{
	IMAGE->FindImage("Player")->CenterRender({ vPos.x + 5, vPos.y + 5 }, 0, { 0.8,0.8 });

}

void obj::Release()
{
}

void obj::Move()
{
	if (DXUTIsKeyDown('W')) {
		vPos.y -= 10;
	}
	else if(DXUTIsKeyDown('S')) {
		vPos.y += 10;

	}
	else if (DXUTIsKeyDown('A')) {
		vPos.x -= 10;

	}
	else if (DXUTIsKeyDown('D')) {
		vPos.x += 10;

	}

}
