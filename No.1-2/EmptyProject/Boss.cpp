#include "DXUT.h"
#include "Boss.h"
#include "Effect.h"
#include "OBullet.h"

void Boss::Init()
{
	GAME->boss = this;
	speedx = 200;
	speedy = 200;
	speedx2 = 400;
	speedy2 = 400;
	sizeTime = new Timer;
	sizeTime->SetTimer(0.8f);
}

void Boss::Update()
{
	SizeTi();
	OBJECT->AddObject("Effect", new Effect(2), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(2), { vPos.x + 5, vPos.y + 5 }, EFFECT);

	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	if (GAME->map[i][j] == 2) {
		GAME->isDie = true;
	}
	if (GAME->map[i + 1][j] != 0 && R == true) {
		speedx *= -1;
		speedx2 *= -1;
		size = 0.6;
		CAMERA->ShakeCamera(100);
		for (int i = 0; i <= 36; i++) {
			OBJECT->AddObject("OBullet", new OBullet(MATH->Rotate(Vector2(0, 1), i * 10)), vPos, UI);
		}
		R = false;
		L = true; D = true; U = true;
	}
	if (GAME->map[i - 1][j] != 0 && L == true){
		speedx *= -1;
		speedx2 *= -1;
		size = 0.6;
		CAMERA->ShakeCamera(100);
		for (int i = 0; i <= 36; i++) {
			OBJECT->AddObject("OBullet", new OBullet(MATH->Rotate(Vector2(0, 1), i * 10)), vPos, UI);
		}
		L = false;
		R = true; D = true; U = true;
	}
	if (GAME->map[i][j + 1] != 0 && D == true) {
		speedy *= -1;
		speedy2 *= -1;
		size = 0.6;
		CAMERA->ShakeCamera(100);
		for (int i = 0; i <= 36; i++) {
			OBJECT->AddObject("OBullet", new OBullet(MATH->Rotate(Vector2(0, 1), i * 10)), vPos, UI);
		}
		D = false;
		R = true; L = true; U = true;
	}
	if (GAME->map[i][j - 1] != 0 && U == true) {
		speedy *= -1;
		speedy2 *= -1;
		size = 0.6;
		CAMERA->ShakeCamera(100);
		for (int i = 0; i <= 36; i++) {
			OBJECT->AddObject("OBullet", new OBullet(MATH->Rotate(Vector2(0, 1), i * 10)), vPos, UI);
		}
		U = false;
		R = true; L = true; D = true;
	}
	
	dir = atan2((vPos.y + speedy) - vPos.y, (vPos.x + speedx) - vPos.x);
}

void Boss::Render()
{
	IMAGE->FindImage("1stage")->CenterRender(vPos, dir, { size,size });
}

void Boss::SizeTi()
{
	if (GAME->isNoMove == false) {

		if (size <= 0.7) {
			if (sizeTime->Update()) {
				isBig = true;
			}
			else {
				isBig = false;
				size = 0.6;
			}
		}
		if (isBig) {
			size += 0.1;
			if (size >= 1) {
				size = 1;
			}
			vPos.x += speedx * D_TIME;
			vPos.y += speedy * D_TIME;
		}
		else {
			vPos.x += speedx2 * D_TIME;
			vPos.y += speedy2 * D_TIME;
		}
	}
}

void Boss::Release()
{
	SAFE_DELETE(sizeTime);
}

void Boss::F()
{
	FloodFile((int)vPos.x / 10, (int)vPos.y / 10);
}

void Boss::FL()
{
	FloodFileQ((int)vPos.x / 10, (int)vPos.y / 10);
}

void Boss::FloodFile(int x, int y)
{
	if (GAME->map[x][y] == 0) {
		GAME->map[x][y] = 6;
		FloodFile(x + 1, y);
		FloodFile(x - 1, y);
		FloodFile(x, y + 1);
		FloodFile(x, y - 1);
	}
}

void Boss::FloodFileQ(int x, int y)
{
	if (GAME->map[x][y] == 6) {
		GAME->map[x][y] = 0;
		FloodFileQ(x + 1, y);
		FloodFileQ(x - 1, y);
		FloodFileQ(x, y + 1);
		FloodFileQ(x, y - 1);
	}
}

