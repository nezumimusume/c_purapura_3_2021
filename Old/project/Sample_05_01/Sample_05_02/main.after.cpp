// Sample_04_04.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include <list>

// step-1 ゲームオブジェクトのインターフェースクラスを実装する。
class IGameObject {
private:
    bool m_isStarted = false;
public:
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    bool IsStarted() const { return m_isStarted; }
    void MarkStared() { m_isStarted = true; }
};
// step-2 GameObjectManagerを実装する
class GameObjectManager {
private:
    std::list<IGameObject*> m_gameObjects;
public:
    void Execute()
    {
        // Start関数が呼ばれていなければ呼び出す。
        for (IGameObject* go : m_gameObjects) {
            if (!go->IsStarted()) {
                go->Start();
                go->MarkStared();
            }
        }
        // Update関数を呼び出す。
        for (IGameObject* go : m_gameObjects) {
            go->Update();
        }
        // Draw関数を呼び出す。
        for (IGameObject* go : m_gameObjects) {
            go->Draw();
        }
    }
    void AddGameObject(IGameObject* go)
    {
        m_gameObjects.push_back(go);
    }
};

// step-3 IGameObjectを継承してプレイヤークラスとエネミークラスを定義する。
class Player : public IGameObject
{
public:
    void Start() { std::cout << "Player::Start\n"; }
    void Update() { std::cout << "Player::Update\n"; }
    void Draw() { std::cout << "Player::Draw\n"; }
};

class Enemy : public IGameObject
{
public:
    void Start() { std::cout << "Enemy::Start\n"; }
    void Update() { std::cout << "Enemy::Update\n"; }
    void Draw() { std::cout << "Enemy::Draw\n"; }
};

int main()
{
    // step-4 GameObjectManagerを使ってみる。
    GameObjectManager goMgr;
    goMgr.AddGameObject(new Player);
    goMgr.AddGameObject(new Enemy);
    // ゲームループ
    while(true) {
        goMgr.Execute();

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
