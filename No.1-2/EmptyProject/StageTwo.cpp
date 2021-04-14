#include "DXUT.h"
#include "StageTwo.h"
#include "Player.h"
#include "Booss.h"
#include "ingameUi.h"
#include "sizeEnemy.h"
#include "AllItem.h"
void StageTwo::Init()
{
	GAME->GameScore = 0;
	GAME->EnemyNum = 5;
	GAME->nowStageNum = 2;
	GAME->nowTime = 180;
	OBJECT->AllClearObject();
	OBJECT->AddObject("Player", new Player, { 100,100 }, PLAYER);
	OBJECT->AddObject("Booss", new Booss, { 715,WINSIZEY / 2 }, ENEMY);
	OBJECT->AddObject("sizeEnemy", new sizeEnemy, { WINSIZEX / 2,WINSIZEY / 2 }, UI);
	OBJECT->AddObject("AllItem", new AllItem, { WINSIZEX / 2,WINSIZEY / 2 }, UI);
	OBJECT->AddObject("ingameUi", new ingameUi, { WINSIZEX / 2,WINSIZEY / 2 }, UI);

}

void StageTwo::Update()
{
	if (GAME->GameScore >= 80) {
		SCENE->ChangeScene("Score");
	}
	if (GAME->BossScore >= 60) {
		GAME->PlayerHp = 0;
	}
	CAMERA->SetCamera({ WINSIZEX / 2, WINSIZEY / 2 });
	if (dir >= 360) {
		dir = 0;
	}
	dir += 0.2 * D_TIME;
}

void StageTwo::Render()
{
	IMAGE->FindImage("1")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 }, dir);
	GAME->m_sprite->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
}

void StageTwo::Release()
{
}
