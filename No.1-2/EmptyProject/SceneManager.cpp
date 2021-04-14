#include "DXUT.h"
#include "SceneManager.h"

void SceneManager::Release()
{
	if (nowScene) {
		nowScene->Release();
	}
	for (auto iter : m_scenes) {
		SAFE_DELETE(iter.second);
	}
	m_scenes.clear();
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

Scene* SceneManager::AddScene(const string& key, Scene* scenePtr)
{
	if(!scenePtr)
		return nullptr;
	if (m_scenes.find(key) != m_scenes.end()) {
		return nullptr;
	}
	m_scenes.insert(make_pair(key, scenePtr));
	return scenePtr;
}

Scene* SceneManager::ChangeScene(const string& key)
{
	auto find = m_scenes.find(key);
	if(find == m_scenes.end())
		return nullptr;
	nextScene = find->second;
	return nextScene;
}

void SceneManager::Update()
{
	if (nextScene) {
		if (nowScene) {
			nowScene->Release();
		}
		OBJECT->AllClearObject();
		nextScene->Init();
		nowScene = nextScene;
		nextScene = nullptr;
	}
	if (nowScene)
		nowScene->Update();
}

void SceneManager::Render()
{
	if (nowScene)
		nowScene->Render();
}
