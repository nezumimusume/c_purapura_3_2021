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
    void Update()
    {
        std::cout << "プレイヤーのHPは:" << m_hp << "です。\n";
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
    void Update(Player* pl)
    {
        std::cout << "敵のHPは:" << m_hp << "です。\n";
        if (pl->GetHP() > m_hp) {
            std::cout << "プレイヤーが優勢です\n";
        }
        else {
            std::cout << "プレイヤーが劣勢です\n";
        }
    }
    void Draw()
    {
        std::cout << "敵の描画処理\n";
    }
};
class Game {
private:
    std::unique_ptr<Player> m_player;
    std::unique_ptr<Enemy> m_enemy;
public:
    Game()
    {
        m_player = std::make_unique<Player>();;
        m_enemy = std::make_unique<Enemy>();
    }
    ~Game()
    {
    }
    void Update()
    {
        m_player->Update();
        m_enemy->Update(m_player.get());
        m_player->Draw();
        m_enemy->Draw();
        
    }
};
int main() {
    SetConsoleOutputCP(CP_UTF8);

    Game game;
    game.Update();

    return 0;
} 