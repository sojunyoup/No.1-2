#pragma once
#include "singleton.h"
#include "Scene.h"
class Scene;
class SceneManager : public singleton<SceneManager>
{
private:
	Scene* nowScene = nullptr;
	Scene* nextScene = nullptr;
	map<string, Scene*>m_scenes;
	void Release();
public:
	SceneManager();
	virtual ~SceneManager();
	Scene* AddScene(const string& key, Scene* scenePtr);
	Scene* ChangeScene(const string& key);
	void Update();
	void Render();
};
#define SCENE SceneManager::GetInstance()
