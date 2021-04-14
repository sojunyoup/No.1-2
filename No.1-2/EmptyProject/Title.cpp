#include "DXUT.h"
#include "Title.h"
#include "Player.h"
#include "Boss.h"
#include "enemy.h"
void Title::Init()
{

	OBJECT->AllClearObject();
	GAME->nowStageNum = 0;
	GAME->AllScore = 0;
	isStart = false;
	Delay = new Timer;
	Delay->SetTimer(0.50f);
}

void Title::Update()
{
	if (Delay->Update()) {
		isStart = true;
	}
	if (DXUTWasKeyPressed('S')) {
		if (numTile >= 4) {
			numTile = 1;
		}
		else {
			numTile++;
		}
	}
	else if (DXUTWasKeyPressed('W')) {
		if (numTile <= 1) {
			numTile = 4;
		}
		else {
			numTile--;
		}
	}
	if (isStart) {
		switch (numTile)
		{
		case 1:
			if (DXUTWasKeyPressed(VK_RETURN)) {
				SCENE->ChangeScene("Stage");
			}
			break;
		case 2:
			if (DXUTWasKeyPressed(VK_RETURN)) {
				SCENE->ChangeScene("Guide");
			}
			break;
		case 3:
			if (DXUTWasKeyPressed(VK_RETURN)) {
				SCENE->ChangeScene("Last");
			}
			break;
		case 4:
			if (DXUTWasKeyPressed(VK_RETURN)) {
				//ExitWindows(0);
			}
			break;
		}
	}
	CAMERA->SetCamera({ WINSIZEX / 2, WINSIZEY / 2 });
}

void Title::Render()
{
	IMAGE->FindImage("Inback")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });

	IMAGE->FindImage("title")->CenterRender({ WINSIZEX / 2, 200 });
	IMAGE->FindImage("start")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2  - 100});
	IMAGE->FindImage("guide")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 +50});
	IMAGE->FindImage("score")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2  + 200});
	IMAGE->FindImage("end")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2  +350});
	switch (numTile)
	{
	case 1:
		IMAGE->FindImage("pick")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 - 100 });

		break;
	case 2:
		IMAGE->FindImage("pick")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 +50});

		break;
	case 3:
		IMAGE->FindImage("pick")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 +200});

		break;
	case 4:
		IMAGE->FindImage("pick")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 +350});

		break;
	}
}

void Title::Release()
{
}
