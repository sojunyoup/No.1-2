#include "DXUT.h"
#include "mainGame.h"
#include "Stage.h"
#include "Title.h"
#include"IntroScene.h"
#include "ScoreScene.h"
#include "StageTwo.h"
#include "LastScene.h"
#include "GuideScene.h"
mainGame::mainGame()
{
	Init();
}

mainGame::~mainGame()
{
	Release();
}

void mainGame::Init()
{
	CAMERA->Reset(); 
	SCENE->AddScene("Intro", new IntroScene);
	SCENE->AddScene("Title", new Title);
	SCENE->AddScene("Stage", new Stage);
	SCENE->AddScene("2Stage", new StageTwo); 
	SCENE->AddScene("Last", new LastScene);
	SCENE->AddScene("Score", new ScoreScene); 
		SCENE->AddScene("Guide", new GuideScene);
	SCENE->ChangeScene("Intro");
}

void mainGame::Update()
{
	SCENE->Update();
	CAMERA->Update();
	OBJECT->Update();
	GAME->Update();
}

void mainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Begin();
	SCENE->Render();
	OBJECT->Render();
	IMAGE->End();
}

void mainGame::Release()
{
	ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	Math::ReleaseInstance();
	Timer::ReleaseInstance();
}

void mainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void mainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}
