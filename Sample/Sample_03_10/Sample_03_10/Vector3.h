#pragma once
#include "math.h"

class Vector3
{
private:
	float m_x = 0.0f;
	float m_y = 0.0f;
	float m_z = 0.0f;
public:
	Vector3()
	{
	}
	Vector3(float x, float y, float z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{
	}
	float Distance(const Vector3& v)
	{
		return static_cast<float>(sqrt(
			(m_x - v.m_x) * (m_x - v.m_x)
			+ (m_y - v.m_y) * (m_y - v.m_y)
			+ (m_z - v.m_z) * (m_z - v.m_z)));
	}
};

