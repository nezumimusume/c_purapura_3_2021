// Effective_07_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <Windows.h>

class IGameObject {
public:
    IGameObject()
    {
        std::cout << "IGameObjectのコンストラクタ\n";
    }
    ~IGameObject()
    {
        std::cout << "IGameObjectのデストラクタ\n";
    }
    virtual void Update()
    {
    }
};
class GameObjectManager {
private:
    std::vector<IGameObject*> m_gameObjects;
public:
    void Execute()
    {
        for (auto go : m_gameObjects) {
            go->Update();
        }
    }
    template<class T>
    T* NewGameObject()
    {
        T* newObj = new T;
        m_gameObjects.push_back(newObj);
        return newObj;
    }
    void DeleteAll()
    {
        for (auto go : m_gameObjects) {
            delete go;
        }
    }
};

class ModelRender {};

class Player : public IGameObject {
private:
    ModelRender* m_modelRender;
public:
    Player()
    {
        std::cout << "Player::コンストラクタ\n";
        m_modelRender = new ModelRender();
    }
    ~Player()
    {
        std::cout << "Player::デストラクタ\n";
        delete m_modelRender;
    }
    void Update()
    {
        std::cout << "Player::Update()\n";
    }
};
class Enemy : public IGameObject {
public:
    void Update()
    {
        std::cout << "Enemy::Update()\n";
    }
};
int main()
{
    GameObjectManager gameObjectManager;
    gameObjectManager.NewGameObject<Player>();

    while (true) {
        if (GetAsyncKeyState('A')) {
            gameObjectManager.DeleteAll();
            break;
        }
        gameObjectManager.Execute();
        Sleep(500);
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
