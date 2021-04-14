#include "DXUT.h"
#include "sizeEnemy.h"
#include "Effect.h"

void sizeEnemy::Init()
{
	speedx2 = 100;
	speedy2 = -100;
	Hp = 2;
	GAME->ashp = 2;
	
}

void sizeEnemy::Update()
{
	Hp = GAME->ashp;
	if (Hp <= 0) {
		isDestroy = true;
	}
	GAME->EnemyPos1 = vPos;
	GAME->EnemyR1 = 70;
	OBJECT->AddObject("Effect", new Effect(4), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(4), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	if (GAME->map[i][j] == 2) {
		GAME->isDie = true;
	}
	if (GAME->map[i + 1][j] == 2 || GAME->map[i - 1][j] == 2 || GAME->map[i][j + 1] == 2 || GAME->map[i][j - 1] == 2) {
		GAME->isDie = true;
	}
	SizeTi();

	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	if (GAME->map[i][j] == 3) {
		GAME->EnemyNum -= 1;
		isDestroy = true;
	}

	if (GAME->map[i + 1][j] != 0 && GAME->map[i + 1][j] != 10 && R == true) {
		speedx2 *= -1;
		R = false;
		L = true; D = true; U = true;
	}
	if (GAME->map[i - 1][j] != 0 && GAME->map[i - 1][j] != 10 && L == true) {
		speedx2 *= -1;
		L = false;
		R = true; D = true; U = true;
	}
	if (GAME->map[i][j + 1] != 0 && GAME->map[i][j + 1] != 10 && D == true) {
		speedy2 *= -1;
		D = false;
		R = true; L = true; U = true;
	}
	if (GAME->map[i][j - 1] != 0 && GAME->map[i][j - 1] != 10 && U == true) {
		speedy2 *= -1;
		U = false;
		R = true; L = true; D = true;
	}

	if (GAME->isNoMove == false) {
		vPos.x += speedx2 * D_TIME;
		vPos.y += speedy2 * D_TIME;
	}

	dir = atan2((vPos.y + speedy2) - vPos.y, (vPos.x + speedx2) - vPos.x);
}

void sizeEnemy::Render()
{
	IMAGE->FindImage("2stage")->CenterRender(vPos, dir, { 1.2, 1.2 });
}

void sizeEnemy::SizeTi()
{
}
void sizeEnemy::Release()
{
}