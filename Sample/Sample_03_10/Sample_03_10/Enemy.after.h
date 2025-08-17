#pragma once
#include "Vector3.h"

class Player; // 前方宣言が使えない

class Enemy
{
private:
	int m_hp = 100;
	int m_mp = 10;
	Vector3 m_position = { 10.0f, 0.0f, 15.0f };
public:
	// 以下のメンバ関数から適切だと考えられるものをインライン化しなさい。
	int GetHp() const
	{
		return m_hp;
	}
	int GetMp() const
	{
		return m_mp;
	}
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	void AttackToPlayer(Player& player);
	
	void TakeDamage(int damage)
	{
		m_hp = std::max<int>(0, m_hp - damage);
	}
};

