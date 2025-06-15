#include <iostream>
#include <Windows.h>
#include <string>


class IGameObject {
private:
    std::string m_name;
public:
    IGameObject(std::string name)
    {
        m_name = name;
    }
};
class Player : public IGameObject {
private:
    int m_hp;
public:
    Player()
    {
        m_hp = 0;
    }
    Player(int hp, std::string name)
    {
        m_hp = hp;
    }
};
class Game{
private:
    Player m_player;
public:
    Game()
    {
        m_player = Player(100, "プレイヤー");
    }
};
int main()
{
   // ゲームをコンストラクト
   Game game;
}