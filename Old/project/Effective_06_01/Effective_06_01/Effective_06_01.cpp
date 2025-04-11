// Effective_05.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

class Player {
    int m_hp;
    int m_mp;
public:
    Player()
    {
    }
    // コピーコンストラクタ
    Player(const Player& pl) = delete;
    // 代入演算子
    Player& operator=(const Player& pl) = delete;
    
    void SetHP(int hp)
    {
        m_hp = hp;
    }
    void SetMp(int mp)
    {
        m_mp = mp;
    }
    void DrawParam()
    {
        std::cout << "HPは" << m_hp << "です。\n";
        std::cout << "MPは" << m_mp << "です。\n";
    }
};
int main()
{
    // デフォルトコンストラクタが呼ばれる。
    Player pl0;
    pl0.SetHP(100);
    pl0.SetMp(20);
    // デフォルトコピーコンストラクタが呼ばれる
    Player pl1(pl0);

    Player pl2;
    // デフォルトの代入演算子が呼ばれる。
    pl2 = pl1;

    pl0.DrawParam();
    pl1.DrawParam();
    pl2.DrawParam();
}
