#include "DXUT.h"
#include "ImageManager.h"

void texture::CenterRender(Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	IMAGE->CenterRender(this, pos, rot, size, color);
}

void texture::Release()
{
	SAFE_RELEASE(texturePtr);
}

void ImageManager::Init()
{
	//인트로
	AddImage("Inback", "Intro/back");
	AddImage("In1", "Intro/1");
	AddImage("In2", "Intro/2");
	//타이틀
	AddImage("title", "Title/title");
	AddImage("start", "Title/start");
	AddImage("guide", "Title/guide");
	AddImage("score", "Title/score");
	AddImage("Guide", "Title/GuideBack");
	AddImage("end", "Title/end");
	AddImage("pick", "Title/pick");
	// 
	//AddImage("A", "A");
	//타이틀
	AddImage("A", "Back/stage");
	AddImage("1", "Back/1");
	AddImage("3", "Back/3");
	AddImage("uiback", "Back/ui");
	//오브젝트
	AddImage("Player", "Player/Player");
	//적
	AddImage("1stage", "Enemy/1");
	AddImage("2stage", "Enemy/2");
	AddImage("1stEnemy", "Enemy/3");
	AddImage("4", "Enemy/4");
	//이팩트
	AddImage("effect", "effect/effect");
	//블릿
	AddImage("Bullet", "Bullet/Bullet");
	//아이템
	AddImage("bu", "item/bu");
	AddImage("bu1", "item/bu1");
	AddImage("bu2", "item/bu2");
	AddImage("Hp", "item/Hp");
	AddImage("sh", "item/sh");
	AddImage("speed", "item/speed");
	AddImage("ASDD", "item/1");
	D3DXCreateSprite(g_device, &m_sprite);
}

void ImageManager::Release()
{
	for (auto iter : m_images) {
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();
	m_sprite->Release();
}

ImageManager::ImageManager()
{
	m_sprite = nullptr;
	Init();
}

ImageManager::~ImageManager()
{
	Release();
}

texture* ImageManager::AddImage(const string& key, const string& path, const int& number)
{
	auto find = m_images.find(key);
	if (find == m_images.end()) {
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;
		char ch[256];
		sprintf(ch, "./Resource/Image/%s.png", path.c_str());
		if (D3DXCreateTextureFromFileExA(g_device, ch, -2, -2, 0, 0,
			D3DFMT_A8B8G8R8, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK) {
			texture* text = new texture(texturePtr,info);
			m_images.insert(make_pair(key, text));
			return text;
		}
		return nullptr;
	}
	return find->second;
}

texture* ImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);
	if(find == m_images.end())
		return nullptr;
	return find->second;
}

void ImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void ImageManager::End()
{
	m_sprite->End();
}

void ImageManager::CenterRender(texture* texturePtr, Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	if (texturePtr) {
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(texturePtr->info.Width / 2, texturePtr->info.Height / 2);
		pos -= CenterPos;
		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void ImageManager::drawText(const string& str, Vector2 pos, float size, D3DCOLOR color, bool Center)
{
	D3DXMATRIX mat;
	if (!Center) {
		D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "System", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else {
		D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "System", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x - size *(str.size() * 0.25), pos.y - size/2.f, 0);
	}
	m_sprite->SetTransform(&mat);
	lpFont->DrawTextA(m_sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
	SAFE_RELEASE(lpFont);
}

void ImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}
