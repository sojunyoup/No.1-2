#include "DXUT.h"
#include "Player.h"
#include "Effect.h"
#include "DieEffect.h"
#include "PlayerBullet.h"
void Player::Init()
{
	GAME->PlayerHp = 5;
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			GAME->map[i][j] = 0;
		}
	}
	GAME->Restartp();
	Restart();
	noMove = new Timer;
	noMove->SetTimer(1.0f);
	ItemT = new Timer;
	ItemT->SetTimer(3.0f);
	bullet = new Timer;
	bullet->SetTimer(0.8f);
	isnoMove = false;
	GAME->m_sprite = IMAGE->FindImage("A");
	Speed = GAME->PlayerSpeed;
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {

		DWORD* texturePixel = (DWORD*)lr.pBits;
		int idx = WINSIZEY * GAME->m_sprite->info.Width + WINSIZEX;
		D3DXCOLOR targetColor = texturePixel[idx];
		bgColor = targetColor;
		texturePixel[idx] = targetColor;

	}
	GAME->m_sprite->texturePtr->UnlockRect(0);

	Restart();
}

void Player::Update()
{
	if (GAME->isSuper) {
		if (ItemT->Update())
			GAME->isSuper = false;
	}
	if (GAME->PlayerSpeed >= 20) {
		if (ItemT->Update())
			GAME->PlayerSpeed = 10;
	}
	if (DXUTWasKeyPressed('Q')) {
		SCENE->ChangeScene("Title");
	}
	Speed = GAME->PlayerSpeed;
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	if (isnoMove == false) {
		Move();	}
	if (GAME->map[i][j] == 1 || GAME->map[i][j] == 4) {
		GAME->isPaintMap = false;
	}
	if (GAME->isPaintMap == true) {
		if (GAME->map[i + 1][j] != 1 || GAME->map[i - 1][j] != 1) {
			if (GAME->map[i + 1][j] != 4 || GAME->map[i - 1][j] != 4) {
				if (DXUTIsKeyDown('A') && DXUTIsKeyDown(VK_SPACE)) {
					if (GAME->map[i - 1][j] == 1 || GAME->map[i - 1][j] == 4) {
						FloodMap();
					}
				}
				if (DXUTIsKeyDown('D') && DXUTIsKeyDown(VK_SPACE)) {
					if (GAME->map[i + 1][j] == 1 || GAME->map[i + 1][j] == 4) {
						FloodMap();
					}
				}
			}
		}
		if (GAME->map[i][j + 1] != 1 || GAME->map[i][j - 1] != 1) {
			if (GAME->map[i][j + 1] != 4 || GAME->map[i][j - 1] != 4) {
				if (DXUTIsKeyDown('W') && DXUTIsKeyDown(VK_SPACE)) {
					if (GAME->map[i][j - 1] == 1 || GAME->map[i][j - 1] == 4) {
						FloodMap();
					}
				}
				if (DXUTIsKeyDown('S') && DXUTIsKeyDown(VK_SPACE)) {
					if (GAME->map[i][j + 1] == 1 || GAME->map[i][j + 1] == 4) {
						FloodMap();
					}
				}
			}
		}
	}
	if (isnoMove == true) {
		if (noMove->Update()) {
			isnoMove = false;
		}
	}
	if (GAME->isSuper == false) {
		if (GAME->isDie == true) {
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { pos.x + 5, pos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { pos.x + 5, pos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { pos.x + 5, pos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { pos.x + 5, pos.y + 5 }, EFFECT);
			}
			isnoMove = true;
			vPos = pos;
			GAME->PlayerDie();
			Restart();
			GAME->PlayerHp -= 1;
			GAME->isDie = false;
		}
	}
	else{
		GAME->isDie = false;
	}
	if (GAME->PlayerHp <= 0) {
		isnoMove = true;
		GAME->isNoMove = true;
		for (int i = 0; i < 20; i++) {
			if (noMove->Update()) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 8), { vPos.x + rand() % 50, vPos.y + rand() % 50 }, EFFECT);
			}
		}
	}
}

void Player::Render()
{
	IMAGE->FindImage("Player")->CenterRender({ vPos.x + 5, vPos.y + 5 }, 0, { 0.8,0.8 });
	if (GAME->isSuper) {
		IMAGE->FindImage("ASDD")->CenterRender({ vPos.x + 5, vPos.y + 5 }, 0, { 0.8,0.8 });
	}
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {

			if (GAME->map[i][j] == 3) {
				//	IMAGE->FindImage("Player")->CenterRender({ (float)i * 10,(float)j * 10 });
			}if (GAME->map[i][j] == 1) {
			//	IMAGE->FindImage("Player")->CenterRender({ (float)i * 10,(float)j * 10 });
			}

		}
	}
}

void Player::Release()
{
	SAFE_DELETE(bullet);
	SAFE_DELETE(ItemT);
	SAFE_DELETE(noMove);
}

void Player::Move()
{
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {
		for (int i = 100; i < 1420; i++) {
			for (int j = 100; j < 980; j++) {
				DWORD* texturePixel = (DWORD*)lr.pBits;
				if (GAME->map[i / 10][j / 10] == 2 || GAME->map[i / 10][j / 10] == 4) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor.a = 1;
					targetColor.r = 1;
					targetColor.g = 1;
					targetColor.b = 1;
					texturePixel[idx] = targetColor;
				}
			}
		}
		GAME->m_sprite->texturePtr->UnlockRect(0);
	}
	if (GAME->isBullet == true) {
		if (DXUTWasKeyPressed(VK_SPACE)) {
			OBJECT->AddObject("PlayerBullet", new PlayerBullet, vPos, UI);
			GAME->bulletgoing += 1;
		}

	}
	if (GAME->bulletgoing >= 3) {
		GAME->isBullet = false;
	}
	if (DXUTIsKeyDown('W')) {
		GAME->dir123 = { 0,-1 };
		if (DXUTIsKeyDown(VK_SPACE)) {
			move = 0;
			for (int x = 1; x <= Speed/10; x++) {
				if (GAME->map[(int)vPos.x/10][(int)vPos.y/10-x] == 0 || GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 - x] == 10) {
					GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 - x] = 2;
					GAME->isPaintMap = true;
					move -= 10;
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				}
			}
			vPos.y += move;
		}
		else {
			move = 0;
			for (int x = 1; x <= Speed/10; x++) {
				if (GAME->map[(int)vPos.x/10][(int)vPos.y/10-x] == 1 || GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 - x] == 4) {
					move -= 10;
				}
			}
			vPos.y += move;
		}
		if (vPos.y <= 97) {
			vPos.y = 100;
		}
	}
	else if (DXUTIsKeyDown('S')) {
		GAME->dir123 = { 0,1 };
		if (DXUTIsKeyDown(VK_SPACE)) {
			if (GAME->map[i][j] == 1 || GAME->map[i][j] == 4) {
				pos = vPos;
			}
			move = 0;
			for (int x = 1; x <= Speed / 10; x++) {
				if (GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 + x] == 0 || GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 + x] == 10) {
					GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 + x] = 2;
					GAME->isPaintMap = true; 
					move += 10;
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				}
			}
			vPos.y += move;
		}
		else {
			move = 0;
			for (int x = 1; x <= Speed / 10; x++) {
				if (GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 + x] == 1 || GAME->map[(int)vPos.x / 10][(int)vPos.y / 10 + x] == 4) {
					move += 10;
				}
			}
			vPos.y += move;
		}
		if (vPos.y >= 971) {
			vPos.y = 970;
		}
	}
	else if (DXUTIsKeyDown('A')) {
		GAME->dir123 = { -1,0 };
		if (DXUTIsKeyDown(VK_SPACE)) {
			move = 0;
			if (GAME->map[i][j] == 1 || GAME->map[i][j] == 4) {
				pos = vPos;
			}
			for (int x = 1; x <= Speed / 10; x++) {
				if (GAME->map[(int)vPos.x / 10 - x][(int)vPos.y / 10] == 0|| GAME->map[(int)vPos.x / 10 - x][(int)vPos.y / 10] == 10) {
					GAME->map[(int)vPos.x / 10 - x][(int)vPos.y / 10] = 2;
					GAME->isPaintMap = true;
					move -= 10;
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				}
			}
			vPos.x += move;
		}
		else {
			move = 0;
			for (int x = 1; x <= Speed / 10; x++) {
				if (GAME->map[(int)vPos.x / 10 - x][(int)vPos.y / 10] == 1 || GAME->map[(int)vPos.x / 10 - x][(int)vPos.y / 10] == 4) {
					move -= 10;
				}
			}
			vPos.x += move;
		}
		if (vPos.x <= 97) {
			vPos.x = 100;
		}
	}
	else if (DXUTIsKeyDown('D')) {
		GAME->dir123 = { 1,0 };
		if (DXUTIsKeyDown(VK_SPACE)) {
			move = 0;
			if (GAME->map[i][j] == 1 || GAME->map[i][j] == 4) {
				pos = vPos;
			}
			for (int x = 1; x <= Speed / 10; x++) {
				if (GAME->map[(int)vPos.x / 10 + x][(int)vPos.y / 10] == 0 || GAME->map[(int)vPos.x / 10 + x][(int)vPos.y / 10] == 10) {
					GAME->map[(int)vPos.x / 10 + x][(int)vPos.y / 10] = 2;
					GAME->isPaintMap = true;
					move += 10;
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
					OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				}
			}
			vPos.x += move;
		}
		else {
			move = 0;
			for (int x = 1; x <= Speed / 10; x++) {
				if (GAME->map[(int)vPos.x / 10 + x][(int)vPos.y / 10] == 1 || GAME->map[(int)vPos.x / 10 + x][(int)vPos.y / 10] == 4) {
					move += 10;
				}
			}
			vPos.x += move;
		}
		if (vPos.x >= 1409) {
			vPos.x = 1410;
		}
	}
}

void Player::FloodMap()
{
	//플러드 필
	if (GAME->nowStageNum == 1) {
		GAME->boss->F();
		for (int i = 10; i < 142; i++) {
			for (int j = 10; j < 98; j++) {
				if (GAME->map[i][j] == 0 || GAME->map[i][j] == 10) {
					GAME->map[i][j] = 3;
				}
			}
		}
		PaintMap();
		GAME->boss->FL();
		GAME->LineDelete();
		GAME->LineDelete();
		PaintMap();
		GAME->isPaintMap = false;
	}
	else if(GAME->nowStageNum == 2){
		GAME->booss->F();
		for (int i = 10; i < 142; i++) {
			for (int j = 10; j < 98; j++) {
				if (GAME->map[i][j] == 0 || GAME->map[i][j] == 10) {
					GAME->map[i][j] = 3;
				}
			}
		}
		PaintMap();
		GAME->booss->FL();
		GAME->LineDelete();
		GAME->LineDelete();
		PaintMap();
		GAME->isPaintMap = false;
	}
}

void Player::PaintMap()
{
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {
		for (int i = 100; i < 1420; i++) {
			for (int j = 100; j < 980; j++) {
				DWORD* texturePixel = (DWORD*)lr.pBits;
				if (GAME->map[i / 10][j / 10] == 3) {
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

void Player::Restart()
{
	if (SUCCEEDED(GAME->m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD))) {
		for (int i = 100; i < 1420; i++) {
			for (int j = 100; j < 980; j++) {
				DWORD* texturePixel = (DWORD*)lr.pBits;
				if (GAME->map[i / 10][j / 10] == 0) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor = bgColor;
					texturePixel[idx] = targetColor;
				}
				if (GAME->map[i / 10][j / 10] == 1) {
					int idx = j * GAME->m_sprite->info.Width + i;
					D3DXCOLOR targetColor = texturePixel[idx];
					targetColor.a = 1;
					targetColor.r = 1;
					targetColor.g = 1;
					targetColor.b = 1;
					texturePixel[idx] = targetColor;
				}
			}
		}
		GAME->m_sprite->texturePtr->UnlockRect(0);
	}
}
