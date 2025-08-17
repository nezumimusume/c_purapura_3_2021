#include <iostream>
#include "Enemy.h"
#include "Player.h"

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
