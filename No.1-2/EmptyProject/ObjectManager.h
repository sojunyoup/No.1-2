#pragma once
#include"singleton.h"
#include "Object.h"
class ObjectManager : public singleton<ObjectManager>
{
	friend class Object;
public:
	ObjectManager();
	virtual ~ObjectManager();
	list<Object*>ObjList[Tag::END];
	Object* AddObject(const string& key, Object* _obj, Vector2 m_pos, Tag _objTag) {
		_obj->Init();
		_obj->m_key = key;
		_obj->vPos = m_pos;
		_obj->m_Tag = _objTag;
		ObjList[_objTag].emplace_back(_obj);
		return _obj;
	};
	Object* FindObject(const string& key) {
		for (auto iter = 0; iter < END; iter++) 
			for (auto iter2 : ObjList[iter]) {
				if (iter2->m_key == key) {
					return iter2;
				}
			}
		return nullptr;
	};
	void Update();
	void Render();
	void Release();
	float isOutMap(Object* obj) {
		if (obj->m_Tag == UI) {
			return false;
		}
		else {
			return (obj->vPos.x < -100 || obj->vPos.x >= WINSIZEX + 100 || obj->vPos.y <= -100|| obj->vPos.y >= WINSIZEY+100);
		}
	};
	void AllClearObject();


};

#define OBJECT ObjectManager::GetInstance()