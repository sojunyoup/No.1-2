#include "DXUT.h"
#include "Effect.h"

Effect::Effect(int number)
{
	num = number;
}

void Effect::Init()
{
}

void Effect::Update()
{
	if (num == 1) {
		size -= 0.02;
	}
	if (num == 2 || num == 3) {
		size -= 0.025f;
	}
	if (num == 4) {
		size -= 0.02;
	}
	if (size <= 0) {
		isDestroy = true;
	}
	
	vPos.x += rand()% 10 - 5;
	vPos.y += rand() % 10 - 5;
	
}

void Effect::Render()
{
	if (num == 1) {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size });
	}
	else if(num == 2) {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size },D3DCOLOR_XRGB(123,18,136));
	}
	else if (num == 3) {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size },D3DCOLOR_XRGB(188, 22, 0));
	}
	else {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size }, D3DCOLOR_XRGB(22, 89, 0));

	}
}

void Effect::Release()
{
}
