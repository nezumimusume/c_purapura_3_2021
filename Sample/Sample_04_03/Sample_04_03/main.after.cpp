#include <iostream>
#include <Windows.h>
#include <memory>

class Player {
private:
    int m_hp = 100;
public:
    ~Player()
    {
        std::cout << "Playerのデストラクタが呼ばれた" << std::endl;
    }
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
    ~Enemy()
    {
        std::cout << "Enemyのデストラクタが呼ばれた" << std::endl;
    }
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
    std::shared_ptr<Player> m_player;
public:
    PlayerUI(std::shared_ptr<Player> player) :
        m_player(player) {
    }
    ~PlayerUI()
    {
        std::cout << "PlayerUIのデストラクタが呼ばれた" << std::endl;
    }
    void Draw()
    {
        std::cout << "プレイヤーのHPは:" << m_player->GetHP() << "です。\n";
    }
};

class EnemyUI {
private:
    std::shared_ptr<Enemy> m_enemy;
public:
    EnemyUI(std::shared_ptr<Enemy> enemy) :
        m_enemy(enemy) 
    {
    }
    ~EnemyUI()
    {
        std::cout << "EnemyUIのデストラクタが呼ばれた" << std::endl;
    }
    void Draw()
    {
        std::cout << "エネミーのHPは:" << m_enemy->GetHP() << "です。\n";
    }
};

class Game {
private:
    std::shared_ptr<Player> m_player;
    std::shared_ptr<Enemy> m_enemy;
    std::shared_ptr<PlayerUI> m_playerUI;
    std::shared_ptr<EnemyUI> m_enemyUI;

public:
    Game()
    {
        m_player = std::make_shared<Player>();
        m_enemy = std::make_shared<Enemy>();    
        m_playerUI = std::make_shared<PlayerUI>(m_player);
        m_enemyUI = std::make_shared<EnemyUI>(m_enemy);
    }
    ~Game()
    {    
        std::cout << "Gameのデストラクタが呼ばれた" << std::endl;
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