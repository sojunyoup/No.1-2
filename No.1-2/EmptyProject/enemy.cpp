#include "DXUT.h"
#include "enemy.h"
#include "Effect.h"

enemy::enemy(int i)
{
	GAME->EnemyR = 30;
	if (i == 1) {
		speedx2 = 400;
			speedy2 = -400;
	}
	Hp = 2;
	GAME->ashp = 2;
}

void enemy::Init()
{
	GAME->isDieEnemy = false;
}

void enemy::Update()
{
	Hp = GAME->ashp;

	if (Hp <= 0) {
		isDestroy = true;
	}
	GAME->EnemyPos = vPos;
	OBJECT->AddObject("Effect", new Effect(2), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	if (GAME->map[i][j] == 2) {
		GAME->isDieEnemy = true;
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
		GAME->isDieEnemy = true;
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

	if (dir >= 360) {
		dir = 0;
	}
	dir += 5.2 * D_TIME;
	if (GAME->isNoMove == false) {
		vPos.x += speedx2 * D_TIME;
		vPos.y += speedy2 * D_TIME;
	}
}

void enemy::Render()
{
	IMAGE->FindImage("1stEnemy")->CenterRender(vPos, dir, { 0.4,0.4 });
}

void enemy::SizeTi()
{
}
void enemy::Release()
{
}