#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

class Player {
public:
    int hp;  // privateデータメンバ
    Player(int initialHp = 100) : hp(initialHp) {}

    // HPを表示する関数
    void DisplayHP() const {
        std::cout << "Player HP: " << hp << std::endl;
    }
};

class Enemy {
private:
    Player* player;
    int damage = 10;

public:
    Enemy(Player* p) : player(p) {}

    void Update()
    {
        if (rand() % 100 < 30) { // 30%の確率で当たる
            // 不変条件のチェックはPlayerクラス内で行われる
            if (player->hp - damage >= 0) {
               player->hp -= damage;
            }
            else {
                player->hp = 0;
            }
        }
    }
};

class DamageFloor {
private:
    Player* player;
    int damage = 5;

public:
    DamageFloor(Player* p) : player(p) {}

    void Update()
    {
        if (rand() % 100 < 30) { // 30%の確率で踏む
            // 不変条件のチェックはPlayerクラス内で行われる
            if (player->hp - damage >= 0) {
               player->hp -= damage;
            }
            else {
                player->hp = 0;
            }
        }
    }
};

class HealItem {
private:
    Player* player;
    int heal =15;
public:
    
    HealItem(Player* p) : player(p) {}

    void Update()
    {
        if (rand() % 100 < 30) { // 30%の確率で踏む
            // 不変条件のチェックはPlayerクラス内で行われる
            if (player->hp + heal <= 100) {
                player->hp += heal;
            }
            else {
                player->hp = 100;
            }
        }
    }
};


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Player player(100);
    Enemy enemy(&player);
    HealItem healItem(&player);
    DamageFloor damageFloor(&player);

    while(true){
        enemy.Update();
        healItem.Update();
        damageFloor.Update();
        player.DisplayHP();
        Sleep(100);
    }
 
    
    return 0;
} 