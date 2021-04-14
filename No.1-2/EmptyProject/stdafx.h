#pragma once
#pragma comment(lib,"dsound.lib")
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string>
#include<map>
#include<list>
#include<algorithm>
#include<vector>

#define g_device DXUTGetD3D9Device()
#define D_TIME DXUTGetElapsedTime() * TimeScale

using namespace std;

const int WINSIZEX = 1920;
const int WINSIZEY = 1080;

static float TimeScale = 1;
static bool isWindow = true;

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;


#include "ImageManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Timer.h"
#include "CameraManager.h"
#include "GameManager.h"
#include "Math.h"