#pragma once
#include "Object.h"
class ingameUi : public Object
{
private:
	//��������
	char nowStage[100000];
	//���� ���� ��
	char nowScore[100000];
	//������ ��, ���� �� ������
	char bossScore[100000];
	//�������� ���� �ð�
	char time[100000];
	//3�� �� Ÿ��Ʋ
	char title[100000];
	//���� �����
	char restart[10000] = "-Enter- �����";
	//��ü ���ھ�
	char allScore[100000];
	//�� ��
	char EnemyCount[100000];
	Timer* timer;
	int my;
	int score;
	int enemy;
	int num = 3;
	Timer* goti;
	bool isF = true;
	bool isF1 = true;
public:
	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

