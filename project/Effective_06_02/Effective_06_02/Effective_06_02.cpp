// Effective_05.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

class ModelRender {
public:
    ModelRender()
    {
    }
    ~ModelRender()
    {
    }
};
class Player {
    ModelRender* m_modelRender = nullptr;
public:
    Player()
    {
        // ModelRenderのインスタンスを作成。
        m_modelRender = new ModelRender;
    }
    ~Player()
    {
        // ModelRenderのインスタンスを破棄。
        delete m_modelRender;
    }
};
int main()
{
    Player pl0; 
#if 0
    Player pl1(pl0);
#else
    Player pl1;
    pl1 = pl0;
#endif
}
