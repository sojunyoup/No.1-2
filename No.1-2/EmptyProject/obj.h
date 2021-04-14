#pragma once
#include "Object.h"
class obj : public Object
{
private:
public:
	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void Move();
};

