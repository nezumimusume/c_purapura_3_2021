#include <iostream>
#include "Player.h"
#include "Enemy.h"

int Player::GetHp() const
{
	return m_hp;
}
int Player::GetMp() const
{
	return m_mp;
}
const Vector3& Player::GetPosition() const
{
	return m_position;
}
void Player::AttackToEnemy(Enemy* enemy)
{
	if (enemy != nullptr
		&& enemy->GetHp() > 0) 
	{
		float distance = m_position.Distance(enemy->GetPosition());
		if (distance < 10.0f) {
			enemy->TakeDamage(10);
		}
	}
}
void Player::TakeDamage(int damage)
{
	m_hp = std::max<int>(0, m_hp - damage);
}
