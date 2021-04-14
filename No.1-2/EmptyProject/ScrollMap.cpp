#include "DXUT.h"
#include "ScrollMap.h"

void ScrollMap::Init()
{
	scrool = 0;
	scrool1 = 0;
	scrool2 = 0;
	Bg = IMAGE->FindImage("In1");
	Bg1 = IMAGE->FindImage("In1");
	Bg2 = IMAGE->FindImage("In2");
}


void ScrollMap::Update()
{
	vPos.x -= 900 * D_TIME;
	if (dir >= 360) {
		dir = 0;
	}
	dir += 0.3 * D_TIME;
}


void ScrollMap::Render()
{
	float bg = (int)scrool % Bg->info.Width;
	IMAGE->CenterRender(Bg, vPos, dir, { 0.8,0.8 });
	float bg1 = (int)scrool1 % Bg1->info.Width;
	IMAGE->CenterRender(Bg1, vPos, dir, { 0.8,0.8 });
}

void ScrollMap::Release()
{
}


