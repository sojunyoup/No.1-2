#pragma once
#include "singleton.h"
class Timer : public singleton<Timer>
{
public:
	Timer();
	~Timer();
	bool Update();
	float m_start = 0;
	float m_delay = 0;
	void SetTimer(float vel) { m_delay = vel; };
};

