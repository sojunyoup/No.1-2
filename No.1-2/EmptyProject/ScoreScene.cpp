#include "DXUT.h"
#include "ScoreScene.h"

void ScoreScene::Init()
{
	for (int i = 10; i < 142; i++) {
		for (int j = 10; j < 98; j++) {
			GAME->map[i][j] = 0;
		}
	}
	GAME->Restartp();
	isStart = false;
	Delay = new Timer;
	Delay->SetTimer(2.0f);
	plueSpeed = new Timer;
	plueSpeed->SetTimer(0.03f);
	nowNum = GAME->GameScore;
	sprintf(now, "%d", nowNum);
	sprintf(all, "%d", (int)GAME->AllScore);
}

void ScoreScene::Update()
{

	sprintf(now, "%d%%", nowNum);
	sprintf(all, "%d점", (int)GAME->AllScore);
	if (Delay->Update()) {
		isStart = true;
	}
	if (isStart == true) {
		if (plueSpeed->Update()) {
			if (nowNum > 0) {
				nowNum -= 1;
				GAME->AllScore += 100;
			}
			else {
				if (DXUTIsKeyDown(VK_RETURN)) {
					if (GAME->nowStageNum == 1) {
						GAME->GameScore = 0;
						SCENE->ChangeScene("2Stage");
					}
					else {
						GAME->GameScore = 0;
						SCENE->ChangeScene("Last");
					}
				}

			}
		}
	}
}

void ScoreScene::Render()
{
	IMAGE->FindImage("Inback")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });

	IMAGE->drawText(scoreTitle, { WINSIZEX / 2 ,200 }, 80, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText("퍼센트", { WINSIZEX / 2 - 100 ,WINSIZEY / 2 - 50 }, 40, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText("총점수", { WINSIZEX / 2 +100 ,WINSIZEY / 2 - 50 }, 40, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(now, { WINSIZEX / 2 - 120,WINSIZEY / 2 }, 60, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText(all, { WINSIZEX / 2 + 100,WINSIZEY / 2 }, 60, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText("-Enter-", { WINSIZEX - 100 ,WINSIZEY - 50 }, 40, D3DCOLOR_XRGB(255, 255, 255), true);

}

void ScoreScene::Release()
{
	SAFE_DELETE(plueSpeed);
	SAFE_DELETE(Delay);
}
