#include "DXUT.h"
#include "CameraManager.h"

CameraManager::CameraManager()
{
	Init();
}

CameraManager::~CameraManager()
{
	Release();
}

void CameraManager::Init()
{
	m_vViewSize = Vector2((float)WINSIZEX, (float)WINSIZEY);
	m_vCameraPos = Vector2(0, 0);
	m_vScale = Vector3(1, 1, 1);
	ShakeTime = 0;
	D3DXMatrixOrthoLH(&m_matProj, m_vViewSize.x, -m_vViewSize.y, 0,1);
}

void CameraManager::Release()
{
}

void CameraManager::SetTransform()
{
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &m_matView);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &m_matProj);
}

void CameraManager::SetCamera(const Vector2& vSetPos)
{
	m_vCameraPos = vSetPos;
}

void CameraManager::Update()
{
	if (ShakeTime >= timeGetTime()) {
		m_vCameraPos += Vector2(rand() % 20 - 10, rand() % 20 - 10);
	}
	D3DXMatrixLookAtLH(&m_matView, &Vector3(m_vCameraPos.x, m_vCameraPos.y, 0), &Vector3(m_vCameraPos.x, m_vCameraPos.y, 10), &Vector3(0, 1, 0));
}

void CameraManager::Reset()
{
	m_vCameraPos = Vector2(WINSIZEX/2, WINSIZEY/2);
	m_vScale = Vector3(1, 1, 1);
}

void CameraManager::ShakeCamera(float _time)
{
	if (ShakeTime <= _time + timeGetTime()) {
		ShakeTime = _time + timeGetTime();
	}
}
