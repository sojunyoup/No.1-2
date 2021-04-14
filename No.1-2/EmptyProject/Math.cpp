#include "DXUT.h"
#include "Math.h"

Vector2 Math::Rotate(Vector2 v, float rot)
{
	float _Rot = D3DXToRadian(rot);
	return Vector2(cos(_Rot) * v.x - sin(_Rot) * v.y, sin(_Rot) * v.x + cos(_Rot) * v.y);
}
