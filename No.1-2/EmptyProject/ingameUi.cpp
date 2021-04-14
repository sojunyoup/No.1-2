#include "DXUT.h"
#include "ingameUi.h"

void ingameUi::Init()
{
	sprintf(nowStage, "STAGE %d", (int)GAME->nowStageNum);
	sprintf(time, "STAGE %d", (int)GAME->nowTime);
	sprintf(nowScore, "My : %d%%", my);
	sprintf(title, "%d초 후 타이틀로 돌아갑니다", num);
	sprintf(allScore, "%d점", (int)GAME->AllScore);
	sprintf(EnemyCount, "%d마리", (int)GAME->GAME->EnemyNum);
	sprintf(bossScore, "En : %d%%", enemy);
	goti = new Timer;
	goti->SetTimer(1.2f);
	timer = new Timer;
	timer->SetTimer(0.5f);
}

void ingameUi::Update()
{
	if (GAME->isPaintMap == false) {
		if (timer->Update()) {
			GAME->nowTime -= 1;
		}
	}
	if (num <= 0) {
		SCENE->ChangeScene("Title");
	}
	if (GAME->isPaintMap == false) {
		if (isF) {
			my = 0;
			for (int i = 10; i < 142; i++) {
				for (int j = 10; j < 98; j++) {
					if (GAME->map[i][j] == 0) {
						my += 1;
					}
				}
			}
			isF = false;
		}
	}
	if (GAME->nowStageNum == 1) {
		enemy = 100 - score;
	}
	else {
		if (isF1) {
			enemy = 0;
			for (int i = 11; i < 141; i++) {
				for (int j = 11; j < 97; j++) {
					if (GAME->Bosmap[i][j] != 10) {
						enemy += 1;
					}
				}
			}
			isF1 = false;
		}
		enemy = (11180 - enemy) / 111.8f;
		GAME->BossScore = enemy;
	}

	score = (11180 - my) / 111.8f;
	GAME->GameScore = score;
	isF = true;
	isF1 = true;
	sprintf(nowStage, "STAGE %d", (int)GAME->nowStageNum);
	sprintf(time, "TIME %d", (int)GAME->nowTime);
	sprintf(bossScore, "En : %d%%", enemy);
	sprintf(nowScore, "My : %d%%", score);
	sprintf(title, "%d초 후 타이틀로 돌아갑니다", num);
	sprintf(allScore, "%d점", (int)GAME->AllScore);
	sprintf(EnemyCount, "%d마리", (int)GAME->GAME->EnemyNum);
	
	
	
	if (GAME->PlayerHp <= 0) {
		if (DXUTWasKeyPressed(VK_RETURN)) {
			if (GAME->nowStageNum == 2) {
				GAME->BossScore = 0;
				for (int i = 11; i < 141; i++) {
					for (int j = 11; j < 97; j++) {
						GAME->Bosmap[i][j] = 0;
					}
				}
				GAME->booss->Clear();
			}
			GAME->isNoMove = false;
			num = 3;
			GAME->PlayerHp = 5;
			GAME->nowTime = 180;
		}
		if (goti->Update()) {
			num -= 1;
		}
	}
}

void ingameUi::Render()
{
	for (int i = 0; i < GAME->PlayerHp; i++) {
		IMAGE->FindImage("Player")->CenterRender({ (float)(1665 - 110 + (i *55)) , 800 }, 0, { 0.8,0.8 });
	}

	IMAGE->drawText(nowStage, { 1665 , 200 }, 50, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(nowScore, { 1665 - 100 , 350 }, 45, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(bossScore, { 1665 + 100, 350 }, 45, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(time, { 1665 , 970 }, 50, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(allScore, { 1665 , 450 }, 50, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(EnemyCount, { 1665 , 600 }, 50, D3DCOLOR_XRGB(255,255,255),true);
	if (GAME->PlayerHp <= 0) {
		IMAGE->FindImage("uiback")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });
		IMAGE->drawText(title, { WINSIZEX / 2 , 1000 }, 30, D3DCOLOR_XRGB(255, 255, 255), true);
		IMAGE->drawText(restart, {WINSIZEX/2 , 1100 }, 30, D3DCOLOR_XRGB(255, 255, 255), true);
	}
}

void ingameUi::Release()
{
	SAFE_DELETE(timer);
}
