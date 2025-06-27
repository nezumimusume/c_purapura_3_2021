// Effective_20.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include "Stopwatch.h"

/// <summary>
/// プレイヤーデータクラス。
/// </summary>
class PlayerData {
    int dummyData[10 * 1024];    //10KBのダミーデータ。
public:
};

/// <summary>
/// ゲームクラス。
/// </summary>
class Game {
private:
    PlayerData m_playerData;
public:
    /// <summary>
    /// プレイヤーデータの設定(コピー渡し)
    /// </summary>
    /// <param name="plData">プレイヤーデータ。</param>
    void SetPlayerData( PlayerData plData ) 
    {
        m_playerData = plData;
    }
    /// <summary>
    /// プレイヤーデータの設定(const参照渡し)
    /// </summary>
    /// <param name="plData">プレイヤーデータ。</param>
    void SetPlayerDataRef(const PlayerData& plData)
    {
        m_playerData = plData;
    }
    /// <summary>
    /// プレイヤーデータの取得(コピー)
    /// </summary>
    /// <returns></returns>
    PlayerData GetPlayerData()
    {
        return m_playerData;
    }
    /// <summary>
    /// プレイヤーデータの取得(const参照)
    /// </summary>
    /// <returns></returns>
    const PlayerData& GetPlayerDataRef()
    {
        return m_playerData;
    }
};

/// <summary>
/// メイン関数。
/// </summary>
/// <returns></returns>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    Game game;
    PlayerData playerData;
    Stopwatch sw;

    //////////////////////////////////////////////
    // 1万回のデータコピー(コピー渡し)
    //////////////////////////////////////////////
    {
        // 時間計測開始。
        sw.Start();

        // 1万回のデータコピーを行う。
        for (int i = 0; i < 10000; i++) {
            game.SetPlayerData(playerData);
        }

        // 時間計測終了。
        sw.Stop();

        // 結果を表示。
        printf("1万回のデータコピー(コピー渡し) = %f\n", sw.GetElapsedMicrosecond());
    }
    //////////////////////////////////////////////
    // 1万回のデータコピー(参照渡し)
    //////////////////////////////////////////////
    {
        // 時間計測開始。
        sw.Start();

        // 1万回のデータコピーを行う。
        for (int i = 0; i < 10000; i++) {
            game.SetPlayerDataRef(playerData);
        }

        // 時間計測終了。
        sw.Stop();

        // 結果を表示。
        printf("1万回のデータコピー(参照渡し) = %f\n", sw.GetElapsedMicrosecond());
    }
    //////////////////////////////////////////////
    // 1万回のデータ取得(コピー)
    //////////////////////////////////////////////
    {
        // 時間計測開始。
        sw.Start();

        // 1万回のデータ取得を行う。
        for (int i = 0; i < 10000; i++) {
            playerData = game.GetPlayerData();
        }

        // 時間計測終了。
        sw.Stop();

        // 結果を表示。
        printf("1万回のデータ取得(コピー) = %f\n", sw.GetElapsedMicrosecond());
    }
    //////////////////////////////////////////////
    // 1万回のデータ取得(const参照)
    //////////////////////////////////////////////
    {
        // 時間計測開始。
        sw.Start();

        // 1万回のデータ取得を行う。
        for (int i = 0; i < 10000; i++) {
            const PlayerData& playerDataRef = game.GetPlayerDataRef();
        }
        
        // 時間計測終了。
        sw.Stop();

        // 結果を表示。
        printf("1万回のデータ取得(const参照) = %f\n", sw.GetElapsedMicrosecond());
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
