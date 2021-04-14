#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	for (int i = NONE + 1; i < END; i++) {
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();) {
			if ((*iter) == nullptr) {
				iter++;
			}
			(*iter)->Release();
			SAFE_DELETE(*iter);
			iter++;
		}
	}
}

void ObjectManager::Update()
{
	for (int i = NONE; i < END; i++) {
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();) {
			if ((*iter)->CheckDestroy()) {
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else if (isOutMap(*iter)) {
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else {
				(*iter)->Update();
				iter++;
			}
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < END; i++) {
		for (auto iter : ObjList[i]) {
			iter->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < END; i++) {
		for (auto iter : ObjList[i]) {
			iter->Release();
		}
	}
}

void ObjectManager::AllClearObject()
{
	for (int i = NONE; i < END; i++) {
		for (auto iter : ObjList[i]) {
			iter->isDestroy = true;
		}
	}
}
