#include <iostream>
#include <Windows.h>
#include <memory>

class Player {
private:
    int m_hp = 100;
public:
    int GetHP() const
    {
        return m_hp;
    }
    void Draw()
    {
        std::cout << "プレイヤーの描画処理\n";
    }
};
class Enemy {
private:
    int m_hp = 20;
public:
    int GetHP() const
    {
        return m_hp;
    }
    void Draw()
    {
        std::cout << "敵の描画処理\n";
    }
};
class PlayerUI {
private:
    Player* m_player;
public:
    PlayerUI(Player* player) :
        m_player(player) {
    }
    void Draw()
    {
        std::cout << "プレイヤーのHPは:" << m_player->GetHP() << "です。\n";
    }
};

class EnemyUI {
private:
    Enemy* m_enemy;
public:
    EnemyUI(Enemy* enemy) :
        m_enemy(enemy) 
    {
    }
    void Draw()
    {
        std::cout << "エネミーのHPは:" << m_enemy->GetHP() << "です。\n";
    }
};

class Game {
private:
    Player* m_player;
    Enemy* m_enemy;
    PlayerUI* m_playerUI;
    EnemyUI* m_enemyUI;

public:
    Game()
    {
        m_player = new Player;
        m_enemy = new Enemy;
        m_playerUI = new PlayerUI(m_player);
        m_enemyUI = new EnemyUI(m_enemy);
    }
    ~Game()
    {
        delete m_player;
        delete m_enemy;
        delete m_playerUI;
        delete m_enemyUI;
    }
    void Update()
    {
        m_player->Draw();
        m_enemy->Draw();
        m_playerUI->Draw();
        m_enemyUI->Draw();
        
    }
};
int main() {
    SetConsoleOutputCP(CP_UTF8);

    Game game;
    game.Update();

    return 0;
} 