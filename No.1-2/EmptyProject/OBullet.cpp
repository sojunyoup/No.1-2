#include "DXUT.h"
#include "OBullet.h"
#include "Effect.h"
OBullet::OBullet(const Vector2& dir, int num)
	:Dir(dir), Num(num)
{
}

void OBullet::Init()
{
}

void OBullet::Update()
{
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	if (Num == 10) {
		if (GAME->map[i][j] == 0) {
			GAME->Bosmap[i][j] = 10;
		}
		OBJECT->AddObject("Effect", new Effect(3), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	}
	else {

		OBJECT->AddObject("Effect", new Effect(2), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	}
	if (GAME->map[i][j] != 0) {
		isDestroy = true;
	}
	if (GAME->map[i][j] == 2) {
		GAME->isDie = true;
	}
	

	vPos += 300 * Dir * D_TIME;
}

void OBullet::Render()
{
	IMAGE->FindImage("Bullet")->CenterRender(vPos, 0, { 1.2,1.2 });
}

void OBullet::Release()
{
}
