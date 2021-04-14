#include "DXUT.h"
#include "GuideScene.h"

void GuideScene::Init()
{
}

void GuideScene::Update()
{
	if (DXUTWasKeyPressed(VK_RETURN)) {
		SCENE->ChangeScene("Title");
	}
}

void GuideScene::Render()
{
	IMAGE->FindImage("Guide")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
}

void GuideScene::Release()
{
}
