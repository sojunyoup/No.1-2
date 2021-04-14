#include "DXUT.h"
#include "IntroScene.h"
#include "ScrollMap.h"
#include "obj.h"

void IntroScene::Init()
{
	introT = new Timer;
	introT->SetTimer(0.08f);
	Scrool = new Timer;
	Scrool->SetTimer(0.5f);
	//OBJECT->AddObject("obj", new obj, { WINSIZEX/2,WINSIZEY / 2 }, PLAYER);

}

void IntroScene::Update()
{
	if (introT->Update()) {
		temp[count] = intro[count];
		count++;
	}
	float i = rand() % WINSIZEY;
	if (Scrool->Update()) {
		OBJECT->AddObject("ScrollMap", new ScrollMap, { WINSIZEX + 90,i }, UI);

	}
	if (DXUTIsKeyDown(VK_RETURN)) {
		SCENE->ChangeScene("Title");
	}
}

void IntroScene::Render()
{
	IMAGE->FindImage("Inback")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });
	IMAGE->drawText(temp, { 100,100 }, 40, D3DCOLOR_XRGB(255, 255, 255), false);

}

void IntroScene::Release()
{
	SAFE_DELETE(introT);
	SAFE_DELETE(Scrool);

}
