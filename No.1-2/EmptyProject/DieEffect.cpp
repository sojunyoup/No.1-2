#include "DXUT.h"
#include "DieEffect.h"
#include "Effect.h"

DieEffect::DieEffect(Vector2 dir, int number)
{
	Dir = dir;
	num = number;
}

void DieEffect::Init()
{
	asd = new Timer;
	asd->SetTimer(0.3f);
}

void DieEffect::Update()
{
	OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);

	if (asd->Update()) {
		isDestroy = true;
	}
	vPos += 300 * Dir * D_TIME;

}

void DieEffect::Render()
{
	if (num == 1 || num == 8) {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size });
	}
	else if (num == 2) {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size }, D3DCOLOR_XRGB(123, 18, 136));
	}
	else if (num == 3) {
		IMAGE->FindImage("effect")->CenterRender(vPos, 0, { size,size }, D3DCOLOR_XRGB(188, 22, 41));
	}
}

void DieEffect::Release()
{
}
