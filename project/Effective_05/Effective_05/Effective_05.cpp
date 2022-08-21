// Effective_05.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

class Player {
    int m_hp;
    int m_mp;
public:
#if 0 // コンパイラが勝手に作成する関数
    // デフォルトコンストラクタ。
    Player()
    {
    }
    // コピーコンストラクタ
    Player(const Player& pl)
    {
        m_hp = pl.m_hp;
        m_mp = pl.m_mp;
    }
    // デフォルトデストラクタ。
    ~Player()
    {
    }
    // 代入演算子
    Player& operator=(const Player& pl)
    {
        if (this == &pl) {
            // 自己代入。
            return *this;
        }
        m_hp = pl.m_hp;
        m_mp = pl.m_mp;
        return *this;
    }
#endif
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
