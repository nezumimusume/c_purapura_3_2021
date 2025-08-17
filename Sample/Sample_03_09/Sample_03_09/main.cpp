#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "Enemy.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Player player;
    Enemy enemy;
    player.AttackToEnemy(&enemy);
    enemy.AttackToPlayer(&player);
    std::cout << "プレイヤーのHP: " << player.GetHp() << std::endl;
    std::cout << "プレイヤーのMP: " << player.GetMp() << std::endl;

    std::cout << "敵のHP: " << enemy.GetHp() << std::endl;
    std::cout << "敵のMP: " << enemy.GetMp() << std::endl;

    return 0;
} 