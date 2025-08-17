#include <iostream>
#include "Player.h"
#include "Enemy.h"


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

