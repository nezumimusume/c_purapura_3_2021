// Effective_07_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <Windows.h>

class IGameObject {
public:
    IGameObject()
    {
        InitBoundingBox();
    }
    virtual ~IGameObject()
    {
        DeleteBoundingBox();
    }
    virtual void InitBoundingBox()
    {
        std::cout << "IGameObject::InitBoundingBox()\n";
    }
    virtual void DeleteBoundingBox()
    {
        std::cout << "IGameObject::DeleteBoundingBox()\n";
    }
    virtual void Update() = 0;
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
    void AddGameObject(IGameObject* go)
    {
        m_gameObjects.push_back(go);
    }
    void DeleteAllGameObjects()
    {
        for (auto go : m_gameObjects) {
            delete go;
        }
    }
};

class Player : public IGameObject {
public:
    void InitBoundingBox()
    {
        std::cout << "Player::InitBoundingBox()";
    }
    void DeleteBoundingBox()
    {
        std::cout << "Player::DeleteBoundingBox()\n";
    }
    void Update()
    { 
        std::cout << "Player::Update()\n";
    }
};

int main()
{
    GameObjectManager gameObjectManager;
    // Playerのコンストラクタが呼ばれる。
    //   ⇒ IGameObjectのコンストラクタが呼ばれる。
    //      ⇒ InitBoundingBox()が呼ばれる。 
    //          
    gameObjectManager.AddGameObject(new Player);
    while (true) {
        gameObjectManager.Execute();
        if (GetAsyncKeyState('A')) {
            break;
        }
        Sleep(500);
    }
    gameObjectManager.DeleteAllGameObjects();
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
