#pragma once
#include "Scene.h"
class IntroScene : public Scene
{
private:
	char intro[100000] = "바이러스를 퇴치하기 위해 나노머신을 조종하여 감염된 영역으로 보낸다....\n감염지역에서 나노머신을 조종하여 바이러스를 물리쳐보자!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n -Enter-";
	char temp[100000];
	int count = 0;
	Timer* introT;
	Timer* Scrool;
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

