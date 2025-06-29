// Effective_20.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include "Stopwatch.h"

/// <summary>
/// Move可能なプレイヤークラス
/// </summary>
class Player {
    int* modelData;
public:
    Player()
    {
        modelData = new int[512*1024*1024];
    }
    ~Player()
    {
        delete[] modelData;
    }
    // コピーコンストラクタ
    Player(const Player& other)
    {
        modelData = new int[512 * 1024 * 1024];
        memcpy(modelData, other.modelData, sizeof(int) * 512 * 1024 * 1024);
    }

    // コピー代入演算子 
    Player& operator=(const Player& other)
    {
        if (this != &other) {
            delete[] modelData;
            modelData = new int[512 * 1024 * 1024];
            memcpy(modelData, other.modelData, sizeof(int) * 512 * 1024 * 1024);
        }
        return *this;
    }
    // ムーブコンストラクタ
    Player(Player&& other) noexcept
    {
        // ポインタの所有権を移動
        modelData = other.modelData;
        // 移動元のポインタをnullptrにする
        other.modelData = nullptr;
    }
    int* GetModelDataAddr() const
    {
        return modelData;
    }
};

Player FuncCopy(Player player)
{
    std::cout << "modelDataのアドレス: " << player.GetModelDataAddr() << std::endl;
    return player;
}
const Player& FuncRef(const Player& player)
{
    std::cout << "modelDataのアドレス: " << player.GetModelDataAddr() << std::endl;
    return player;
}

Player FuncMove(Player player)
{
    std::cout << "modelDataのアドレス: " << player.GetModelDataAddr() << std::endl;
    return std::move(player);
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    Player player;
    Stopwatch sw;
    
    // コピーの時間を計測
    sw.Start();
    FuncCopy(player);
    sw.Stop();
    std::cout << "コピーの時間: " << sw.GetElapsed() << "ミリ秒\n";

    // 参照の時間を計測 
    sw.Start();
    FuncRef(player);
    sw.Stop();
    std::cout << "参照の時間: " << sw.GetElapsed() << "ミリ秒\n";

    // Moveの時間を計測
    sw.Start(); 
    player = FuncMove(std::move(player));
    sw.Stop();
    std::cout << "Moveの時間: " << sw.GetElapsed() << "ミリ秒\n";

    return true;
}
