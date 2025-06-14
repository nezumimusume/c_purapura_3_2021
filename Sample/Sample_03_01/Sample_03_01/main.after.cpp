#include <iostream>
#include <Windows.h>
#include <string>

class Player {
private:
    int hp;
    int attack;
    std::string name;

public:
    // コンストラクタ
    Player(const std::string& playerName, int initialHp, int initialAttack) 
        : name(playerName), hp(initialHp), attack(initialAttack) {}

    // constを付けたメンバ関数
    int GetHP() const { 
        return hp; 
    }

    int GetAttack() const {
        return attack;
    }

    std::string GetName() const {
        return name;
    }

    void TakeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }
};

// プレイヤーの状態を表示する関数（constな参照を使用）
void DisplayPlayerStatus(const Player& player) {
    // constメンバ関数なのでコンパイルエラーは発生しない
    std::cout << "名前: " << player.GetName() << "\n";
    std::cout << "HP: " << player.GetHP() << "\n";
    std::cout << "攻撃力: " << player.GetAttack() << "\n";
}

// プレイヤー同士の戦闘をシミュレートする関数
void SimulateBattle(const Player& attacker, Player& defender) {
    // constメンバ関数なのでコンパイルエラーは発生しない
    std::cout << attacker.GetName() << "が" << defender.GetName() << "に攻撃！\n";
    int damage = attacker.GetAttack();
    std::cout << "与えたダメージ: " << damage << "\n";
    
    // defenderはconstではないのでTakeDamageを呼び出せる
    defender.TakeDamage(damage);
    // GetNameとGetHPはconstメンバ関数なので呼び出せる
    std::cout << defender.GetName() << "の残りHP: " << defender.GetHP() << "\n";
}

int main() {
    Player hero("勇者", 100, 15);
    Player enemy("スライム", 50, 5);

    // この関数呼び出しはコンパイルエラーが発生しない
    DisplayPlayerStatus(hero);
    std::cout << "\n";
    
    // この関数呼び出しもコンパイルエラーが発生しない
    SimulateBattle(hero, enemy);

    return 0;
} 