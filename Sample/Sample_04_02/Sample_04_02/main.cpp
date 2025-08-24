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
    Player* m_player;
    Enemy* m_enemy;
public:
    Game()
    {
        m_player = new Player;
        m_enemy = new Enemy;
    }
    ~Game()
    {
        delete m_player;
        delete m_enemy;
    }
    void Update()
    {
        m_player->Update();
        m_enemy->Update(m_player);
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