#include "DXUT.h"
#include "LastScene.h"

void LastScene::Init()
{
	ScoreList.push_back(GAME->AllScore);
	ScoreList.push_back(0);
	ScoreList.push_back(0);
	ScoreList.push_back(0);
	ScoreList.sort([](int a, int b) {return a > b; });
	bam = new Timer;
	bam->SetTimer(3.0f);
	next = false;
}

void LastScene::Update()
{
	if (bam->Update()) {
		next = true;
	}
	if (next) {
		if (DXUTIsKeyDown(VK_RETURN)) {
			GAME->AllScore = 0;
			SCENE->ChangeScene("Title");
		}
	}
}

void LastScene::Render()
{
	IMAGE->FindImage("Inback")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });

	IMAGE->drawText("-RNKING-", { (float)WINSIZEX / 2, (float)WINSIZEY / 2 - 300 }, 100, D3DCOLOR_XRGB(255, 255, 255), true);

	IMAGE->drawText("1. ", { (float)WINSIZEX / 2 - 80, (float)WINSIZEY / 2 }, 70, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText("2. ", { (float)WINSIZEX / 2 - 80, (float)(WINSIZEY / 2 + 100) }, 70, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->drawText("3. ", { (float)WINSIZEX / 2 - 80, (float)(WINSIZEY / 2 + 200) }, 70, D3DCOLOR_XRGB(255, 255, 255), true);



	int i = 0;
	for (auto iter : ScoreList) {
		IMAGE->drawText(to_string(iter), {(float)WINSIZEX/2, (float)(WINSIZEY/2 + (i * 100))}, 70,D3DCOLOR_XRGB(255,255,255), true);
		if(i >= 2)i += 20;
		else { i += 1; }
	}
}

void LastScene::Release()
{
}
