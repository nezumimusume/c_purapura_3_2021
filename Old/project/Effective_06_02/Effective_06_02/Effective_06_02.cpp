// Effective_05.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

class ModelRender {
    int* m_vertexBuffer;
public:
    ModelRender() = default;
    ModelRender(ModelRender& modelRender) = delete;
    ModelRender& operator=(ModelRender& modelRender) = delete;

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
    ModelRender GetModelRender()
    {
        return m_modelRender;
    }
    
};
void Func(ModelRender render)
{
}
int main()
{
    Player pl0; 
    ModelRender render = pl0.GetModelRender();
    Func(render);
}
