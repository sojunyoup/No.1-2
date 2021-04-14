#pragma once
class mainGame 
{
public:
	mainGame();
	virtual ~mainGame();
	void Init();
	void Update();
	void Render();
	void Release();
	void LostDevice();
	void ResetDevice();
};

