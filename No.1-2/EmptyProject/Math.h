#pragma once
#include "singleton.h"
class Math : public singleton<Math>
{
public:
	Vector2 Rotate(Vector2 v, float rot);
	template<typename T>
	void Lerp(T* target, T& start, T& end, float time) {
		*target = start + (end - start) * time * D_TIME; 
	}
};

#define MATH Math::GetInstance()