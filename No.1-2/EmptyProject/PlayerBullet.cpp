#include "DXUT.h"
#include "PlayerBullet.h"
#include "Effect.h"
void PlayerBullet::Init()
{
	r = 6;
	i = new Timer;
	i->SetTimer(1.0f);
	tur = false;
	dir = GAME->dir123;
}

void PlayerBullet::Update()
{
	OBJECT->AddObject("Effect", new Effect(1), { vPos.x + 5, vPos.y + 5 }, EFFECT);

	if (GAME->nowStageNum == 1) {
		if (GAME->bulletP == 1) {
			Vector2 temp = Vector2(GAME->EnemyPos.x, GAME->EnemyPos.y) - Vector2(vPos.x, vPos.y);
			if (D3DXVec2Length(&temp) < r + GAME->EnemyR) {
				isDestroy = true;
			}
			vPos += dir * 1000 * D_TIME;
		}
		else if(GAME->bulletP == 2){
			if (i->Update()) {
				tur = true;
			}
			Vector2 temp = Vector2(GAME->EnemyPos.x, GAME->EnemyPos.y) - Vector2(vPos.x, vPos.y);
			if (D3DXVec2Length(&temp) < r + GAME->EnemyR) {
				GAME->ashp -= 1;
				isDestroy = true;
			}
			if (GAME->isDieEnemy == false) {
				if (tur == false) {
					D3DXVec2Normalize(&temp, &temp);
					MATH->Lerp<Vector2>(&dir, dir, temp, 3.0f);
				}
			}
			vPos += dir * 1000 * D_TIME;
		}
	}
	else if (GAME->nowStageNum == 2) {
		if (GAME->bulletP == 1) {
			Vector2 temp = Vector2(GAME->EnemyPos1.x, GAME->EnemyPos1.y) - Vector2(vPos.x, vPos.y);
			if (D3DXVec2Length(&temp) < r + GAME->EnemyR1) {
				isDestroy = true;
			}
			vPos += dir * 1000 * D_TIME;
		}
		else if (GAME->bulletP == 2) {
			if (i->Update()) {
				tur = true;
			}
			Vector2 temp = Vector2(GAME->EnemyPos1.x, GAME->EnemyPos1.y) - Vector2(vPos.x, vPos.y);
			if (D3DXVec2Length(&temp) < r + GAME->EnemyR1) {
				isDestroy = true;
			}
			if (GAME->isDieEnemy == false) {
				if (tur == false) {
					D3DXVec2Normalize(&temp, &temp);
					MATH->Lerp<Vector2>(&dir, dir, temp, 3.0f);
				}
			}
			vPos += dir * 1000 * D_TIME;
		}
	}
}

void PlayerBullet::Render()
{
	IMAGE->FindImage("Bullet")->CenterRender(vPos, 0, { 1.2,1.2 });

}

void PlayerBullet::Release()
{
}
