#include "DXUT.h"
#include "Stage.h"
#include "Player.h"
#include "Boss.h"
#include "enemy.h"
#include "ingameUi.h"
#include "AllItem.h"

void Stage::Init()
{
	GAME->GameScore = 0;
	GAME->EnemyNum = 2;
	GAME->nowStageNum = 1;
	GAME->nowTime = 180;
	OBJECT->AllClearObject();
	OBJECT->AddObject("Player", new Player, { 100,100 }, PLAYER);
	OBJECT->AddObject("Boss", new Boss, { 715,WINSIZEY / 2 }, ENEMY);
	OBJECT->AddObject("ingameUi", new ingameUi, { WINSIZEX / 2,WINSIZEY / 2 }, UI);
	OBJECT->AddObject("AllItem", new AllItem, { WINSIZEX / 2,WINSIZEY / 2 }, UI);
	OBJECT->AddObject("enemy", new enemy(1), { 715,WINSIZEY / 2 }, ENEMY);
}

void Stage::Update()
{
	if (GAME->GameScore >= 80) {
		SCENE->ChangeScene("Score");
	}
	CAMERA->SetCamera({ WINSIZEX / 2, WINSIZEY / 2 });
	if (dir >= 360) {
		dir = 0;
	}
	dir += 0.2 * D_TIME;
}

void Stage::Render()
{

	IMAGE->FindImage("1")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 }, dir);
	GAME->m_sprite->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
}

void Stage::Release()
{
}
