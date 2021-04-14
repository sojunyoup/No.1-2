#include "DXUT.h"
#include "Booss.h"
#include "Effect.h"
#include "OBullet.h"
void Booss::Init()
{
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			GAME->Bosmap[i][j] = 0;
		}
	}
	GAME->booss = this;
	speedx = 5;
	speedy = 5;
	sizeTime = new Timer;
	sizeTime->SetTimer(0.5f);
	pater = new Timer;
	pater->SetTimer(7.0f);
	asdf = new Timer;
	asdf->SetTimer(2.0f);
	is = true;
	Qpater = false;
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {

		DWORD* texturePixel = (DWORD*)lr.pBits;
		int idx = WINSIZEY * GAME->m_sprite->info.Width + WINSIZEX;
		D3DXCOLOR targetColor = texturePixel[idx];
		bgColor = targetColor;
		texturePixel[idx] = targetColor;

	}
	GAME->m_sprite->texturePtr->UnlockRect(0);
	
}

void Booss::Update()
{
	if (is) {
		for (int i = 0; i <= 36; i++) {
			OBJECT->AddObject("OBullet", new OBullet(MATH->Rotate(Vector2(0, 1), i * 10), 10), vPos, UI);

		}
		is = false;
	}
	r.right = vPos.x + 5;
	r.top = vPos.y - 5;
	r.left = vPos.x - 5;
	r.bottom = vPos.y + 5;
	SizeTi();
	OBJECT->AddObject("Effect", new Effect(3), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(3), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(3), { vPos.x + 5, vPos.y + 5 }, EFFECT);
	OBJECT->AddObject("Effect", new Effect(3), { vPos.x + 5, vPos.y + 5 }, EFFECT);

	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	if (GAME->Bosmap[i][j] == 0) {
		GAME->Bosmap[i][j] = 10;
	}
	if (GAME->map[i + 1][j] == 2 || GAME->map[i - 1][j] == 2 || GAME->map[i][j + 1] == 2 || GAME->map[i - 1][j] == 2) {
		GAME->isDie = true;
	}
	if (Qpater == false) {
		if (pater->Update()) {
			Qpater = true;
		}
	}
	else {
		if (asdf->Update()) {
			Qpater = false;
		}
	}
	
	if (GAME->isNoMove == false) {
		i = ceil(vPos.x / 10);
		j = ceil(vPos.y / 10);
		if (GAME->map[i][j] == 2) {
			GAME->isDie = true;

		}
		if (GAME->map[i + 1][j] != 0 && GAME->map[i + 1][j] != 10 && R == true) {
			speedx *= -1;
			CAMERA->ShakeCamera(100);
			R = false;
			L = true; D = true; U = true;
		}
		if (GAME->map[i - 1][j] != 0 && GAME->map[i - 1][j] != 10 && L == true) {
			speedx *= -1;
			CAMERA->ShakeCamera(100);
			L = false;
			R = true; D = true; U = true;
		}
		if (GAME->map[i][j + 1] != 0 && GAME->map[i][j + 1] != 10 && D == true) {
			speedy *= -1;
			CAMERA->ShakeCamera(100);
			D = false;
			R = true; L = true; U = true;
		}
		if (GAME->map[i][j - 1] != 0 && GAME->map[i][j - 1] != 10 && U == true) {
			speedy *= -1;
			CAMERA->ShakeCamera(100);
			U = false;
			R = true; L = true; D = true;
		}
		vPos.x += speedx;
		vPos.y += speedy;
		
	}
	if (Qpater == true && GAME->isNoMove == false) {

		if (sizeTime->Update()) {
			for (int i = 0; i <= 36; i++) {
				OBJECT->AddObject("OBullet", new OBullet(MATH->Rotate(Vector2(0, 1), i * 10), 10), vPos, UI);

			}
		}
	}
	GAME->m_sprite = IMAGE->FindImage("A");
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			if (GAME->Bosmap[i][j] == 10 || GAME->Bosmap[i][j] == 0) {
				if (GAME->map[i][j] == 3) {
					GAME->Bosmap[i][j] = 3;
				}
				if (GAME->map[i][j] == 4) {
					GAME->Bosmap[i][j] = 4;
				}
			}
			if (GAME->Bosmap[i][j] == 4) {
				if (GAME->map[i][j] == 3) {
					GAME->Bosmap[i][j] = 3;
				}
			}
		}
	}
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {
		for (int i = 110; i < 1410; i++) {
			for (int j = 110; j < 970; j++) {
				DWORD* texturePixel = (DWORD*)lr.pBits;
				if (GAME->Bosmap[i / 10][j / 10] == 10) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor.a = 1;
					targetColor.r = 0.5;
					targetColor.g = 0.22;
					targetColor.b = 0.41;
					texturePixel[idx] = targetColor;
				}
				if (GAME->Bosmap[i / 10][j / 10] == 4) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor.a = 1;
					targetColor.r = 1;
					targetColor.g = 1;
					targetColor.b = 1;
					texturePixel[idx] = targetColor;
				}
				if (GAME->Bosmap[i / 10][j / 10] == 3) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor.a = 0;
					texturePixel[idx] = targetColor;
				}
			}
		}
		GAME->m_sprite->texturePtr->UnlockRect(0);
	}
}

void Booss::Render()
{
	IMAGE->FindImage("4")->CenterRender(vPos, dir, { size,size });
}

void Booss::SizeTi()
{
}
void Booss::Clear()
{
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {
		for (int i = 110; i < 1410; i++) {
			for (int j = 110; j < 970; j++) {
				DWORD* texturePixel = (DWORD*)lr.pBits;
				if (GAME->Bosmap[i / 10][j / 10] == 0) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor = bgColor;
					texturePixel[idx] = targetColor;
				}
			}
		}
		GAME->m_sprite->texturePtr->UnlockRect(0);
	}
}
void Booss::Release()
{
	SAFE_DELETE(sizeTime);
	SAFE_DELETE(asdf);
	SAFE_DELETE(pater);
}
void Booss::F()
{
	FloodFile((int)vPos.x / 10, (int)vPos.y / 10);
}

void Booss::FL()
{
	FloodFileQ((int)vPos.x / 10, (int)vPos.y / 10);
}

void Booss::FloodFile(int x, int y)
{
	if (GAME->map[x][y] == 0 || GAME->map[x][y] == 10) {
			GAME->map[x][y] = 6;
		
		FloodFile(x + 1, y);
		FloodFile(x - 1, y);
		FloodFile(x, y + 1);
		FloodFile(x, y - 1);
	}
}

void Booss::FloodFileQ(int x, int y)
{
	if (GAME->map[x][y] == 6 || GAME->map[x][j] == 10) {
		GAME->map[x][y] = 0;
		FloodFileQ(x + 1, y);
		FloodFileQ(x - 1, y);
		FloodFileQ(x, y + 1);
		FloodFileQ(x, y - 1);
	}
}

