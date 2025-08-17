#include <iostream>
#include "Enemy.h"
#include "Player.h"

int Enemy::GetHp() const
{
	return m_hp;
}
int Enemy::GetMp() const
{
	return m_mp;
}
const Vector3& Enemy::GetPosition() const
{
	return m_position;
}
void Enemy::AttackToPlayer(Player* pl)
{
	if (pl != nullptr
		&& pl->GetHp() > 0)
	{
		float distance = m_position.Distance(pl->GetPosition());
		if (distance < 10.0f) {
			pl->TakeDamage(10);
		}
	}
}
void Enemy::TakeDamage(int damage)
{
	m_hp = std::max<int>(0, m_hp - damage);
}
