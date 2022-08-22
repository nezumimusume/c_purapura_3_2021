// Effective_05.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

class ModelRender {
    int* m_vertexBuffer;
public:
    ModelRender()
    {
        m_vertexBuffer = new int;
    }
    ~ModelRender()
    {
        delete m_vertexBuffer;
    }
};
class Player {
    ModelRender m_modelRender;
public:
    Player()
    {
    }
    ~Player()
    {
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
