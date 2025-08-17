#include <iostream>
#include "Enemy.h"
#include "Player.h"


void Enemy::AttackToPlayer(Player& player)
{
	if (player.GetHp() > 0)
	{
		float distance = m_position.Distance(player.GetPosition());
		if (distance < 10.0f) {
			player.TakeDamage(10);
		}
	}
}