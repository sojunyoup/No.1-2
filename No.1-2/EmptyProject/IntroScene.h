#pragma once
#include "Scene.h"
class IntroScene : public Scene
{
private:
	char intro[100000] = "���̷����� ��ġ�ϱ� ���� ����ӽ��� �����Ͽ� ������ �������� ������....\n������������ ����ӽ��� �����Ͽ� ���̷����� �����ĺ���!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n -Enter-";
	char temp[100000];
	int count = 0;
	Timer* introT;
	Timer* Scrool;
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

