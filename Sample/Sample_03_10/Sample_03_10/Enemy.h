#pragma once
#include "Vector3.h"

#include "Player.h" // 前方宣言が使えないので泣く泣く#includeを利用している
// class Player; // 前方宣言が使えない

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
	void AttackToPlayer(Player& player)
	{
		if (player.GetHp() > 0)
		{
			float distance = m_position.Distance(player.GetPosition());
			if (distance < 10.0f) {
				player.TakeDamage(10);
			}
		}
	}
	void TakeDamage(int damage)
	{
		m_hp = std::max<int>(0, m_hp - damage);
	}
};

