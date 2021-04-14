#include "DXUT.h"
#include "AllItem.h"
#include "Item.h"
void AllItem::Init()
{
	//1 = speed, 2 = super 3 = hp
	iteamCreat = new Timer;
	iteamCreat->SetTimer(15.0f);
	isTrue = false;
}

void AllItem::Update()
{
	i = rand() % 131 + 10;
	j = rand() % 88 + 10;
	if (GAME->map[i][j] == 0) {
		Ipos = Vector2((float)i*10,(float)j*10);
	}
	if (iteamCreat->Update()) {
		item = rand() % 5;
	}
	if (item == 0) {
		if (sp <= 0) {
			item = rand() % 5;
		}
		else {
			isTrue = true;
			sp -= 1;
		}
		//½ºÇÇµå
	}
	else if (item == 1) {
		if (su <= 0) {
			item = rand() % 5;
		}
		else {
			isTrue = true;
			su -= 1;
		}//¹«Àû
	}
	else if (item == 2) {
		if (hp <= 0) {
			item = rand() % 5;
		}
		else {
			isTrue = true;
			hp -= 1;
		}//hp
	}
	else if (item == 3) {
		if (GAME->isDieEnemy) {
			item = rand() % 5;
		}
		if (bu <= 0) {
			item = rand() % 5;
		}
		else {
			isTrue = true;
			bu -= 1;
		}//ÃÑ¤©
	}
	else if (item == 4) {
		if (GAME->isDieEnemy) {
			item = rand() % 5;
		}
		if (bu1 <= 0) {
			item = rand() % 5;
		}
		else {
			isTrue = true;
			bu1 -= 1;
		}//ÃÑ
	}
	if (isTrue) {
		OBJECT->AddObject("item", new Item(item), Ipos, UI);
		item = 10;
		isTrue = false;
	}

}

void AllItem::Render()
{
}

void AllItem::Release()
{
}
