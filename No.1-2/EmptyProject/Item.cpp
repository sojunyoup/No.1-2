#include "DXUT.h"
#include "Item.h"
#include "DieEffect.h"
Item::Item(int num)
	:Num(num)
{
}

void Item::Init()
{

}

void Item::Update()
{
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	if (GAME->map[i][j] == 2 || GAME->map[i][j] == 3 || GAME->map[i][j] == 4) {
		switch (Num)
		{
		case 0:
			//스피드
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
			}
			GAME->PlayerSpeed = 20;
			GAME->isSuper = true;
			isDestroy = true;
			break;
		case 1:
			//무적
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
			}
			GAME->PlayerSpeed = 10;
			GAME->isSuper = true;
			isDestroy = true; break;
		case 2:
			//hp
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
			}
			GAME->PlayerSpeed = 10;
			if(GAME->PlayerHp < 5)
				GAME->PlayerHp += 1;
			isDestroy = true; break;
		case 3:
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
			}
			GAME->bulletP = 1; GAME->isBullet = true;
			GAME->bulletgoing = 0; isDestroy = true; break;
		case 4:
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
			}
			GAME->bulletP = 2; GAME->isBullet = true;
			GAME->bulletgoing = 0; isDestroy = true; break;
		case 5:
			for (int i = 0; i < 20; i++) {
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
				OBJECT->AddObject("DieEffect", new DieEffect(MATH->Rotate(Vector2(0, 1), i * 18), 1), { vPos.x + 5, vPos.y + 5 }, EFFECT);
			}
			GAME->bulletP = 3; GAME->isBullet = true;
			GAME->bulletgoing = 0; isDestroy = true; break;

		}
	}
}

void Item::Render()
{
	switch (Num)
	{
	case 0:
		IMAGE->FindImage("speed")->CenterRender(vPos, 0, {2.0f,2.0f});
		break;
	case 1:
		IMAGE->FindImage("sh")->CenterRender(vPos, 0, { 2.0f,2.0f });
		break;
	case 2:
		IMAGE->FindImage("Hp")->CenterRender(vPos, 0, { 2.0f,2.0f });
		break;
	case 3:
		IMAGE->FindImage("bu")->CenterRender(vPos, 0, { 2.0f,2.0f });
		break;
	case 4:
		IMAGE->FindImage("bu1")->CenterRender(vPos, 0, { 2.0f,2.0f });
		break;			  
	case 5:				  
		IMAGE->FindImage("bu2")->CenterRender(vPos, 0, { 2.0f,2.0f });

		break;
	}
}

void Item::Release()
{
}
