#pragma once
enum ObjTag :char {
	NONE,
	PLAYER,
	EFFECT,
	ENEMY,
	UI,
	END,
}typedef Tag;
class Object
{
public:
	Object();
	virtual ~Object();
	Vector2 vPos = { 0,0 };
	string m_key;
	Tag m_Tag;
	int Hp;
	texture* image = nullptr;
	bool isDestroy = false;
	virtual void Init()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	bool CheckDestroy() { return isDestroy; }
};

