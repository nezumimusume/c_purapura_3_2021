#pragma once
#include "Vector3.h"

class Player;

class Enemy
{
private:
	int m_hp = 100;
	int m_mp = 10;
	Vector3 m_position = { 10.0f, 0.0f, 15.0f };
public:
	// 以下のメンバ関数から適切だと考えられるものをインライン化しなさい。
	int GetHp() const;
	int GetMp() const;
	const Vector3& GetPosition() const;
	void AttackToPlayer(Player* player);
	void TakeDamage(int damage);
};

