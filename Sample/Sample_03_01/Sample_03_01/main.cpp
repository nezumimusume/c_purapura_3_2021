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

    // constを付けていないメンバ関数
    int GetHP() { 
        return hp; 
    }

    int GetAttack() {
        return attack;
    }

    std::string GetName() {
        return name;
    }

    void TakeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }
};

// プレイヤーの状態を表示する関数（constな参照を使用）
void DisplayPlayerStatus(const Player& player) {
    // コンパイルエラー: constなPlayerオブジェクトにconstでないメンバ関数は呼び出せない
    std::cout << "名前: " << player.Get5Name() << "\n";
    std::cout << "HP: " << player.GetHP() << "\n";
    std::cout << "攻撃力: " << player.GetAttack() << "\n";
}

// プレイヤー同士の戦闘をシミュレートする関数
void SimulateBattle(const Player& attacker, Player& defender) {
    // コンパイルエラー: attackerがconstなのでconstでないメンバ関数は呼び出せない
    std::cout << attacker.GetName() << "が" << defender.GetName() << "に攻撃！\n";
    int damage = attacker.GetAttack();
    std::cout << "与えたダメージ: " << damage << "\n";
    
    // defenderはconstではないのでTakeDamageは呼び出せるが、
    // GetNameやGetHPがconstでないため、コンパイルエラーが発生する
    defender.TakeDamage(damage);
    std::cout << defender.GetName() << "の残りHP: " << defender.GetHP() << "\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Player hero("勇者", 100, 15);
    Player enemy("スライム", 50, 5);

    // この関数呼び出しでコンパイルエラーが発生
    DisplayPlayerStatus(hero);
    std::cout << "\n";
    
    // この関数呼び出しでもコンパイルエラーが発生
    SimulateBattle(hero, enemy);

    return 0;
} 