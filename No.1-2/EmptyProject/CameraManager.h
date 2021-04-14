#pragma once
#include "singleton.h"
class CameraManager : public singleton<CameraManager>
{
private:
	
public:
	CameraManager();
	virtual ~CameraManager();
	D3DXMATRIX m_matProj, m_matView;
	Vector2 m_vViewSize, m_vCameraPos;
	Vector3 m_vScale;
	float ShakeTime;

	void Init();
	void Release();
	void SetTransform();
	void SetCamera(const Vector2& vSetPos);
	void Update();
	void Reset();
	void ShakeCamera(float _time);
};

#define CAMERA CameraManager::GetInstance()