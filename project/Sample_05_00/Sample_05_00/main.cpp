// Sample_04_04.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>

class Fit {
public:
    void Move(){ std::cout << "Fit::Move()\n"; }
    void Brake(){ std::cout << "Fit::Brake()\n"; }
    void Accele(){ std::cout << "Fit::Accele()\n"; }
};

class Bits {
public:
    void Move(){ std::cout << "Bits::Move()\n"; }
    void Brake(){ std::cout << "Bits::Brake()\n"; }
    void Accele(){ std::cout << "Bits::Accele()\n"; }
};

class WagonR {
public:
    void Move() { std::cout << "WagonR::Move()\n"; }
    void Brake() { std::cout << "WagonR::Brake()\n"; }
    void Accele() { std::cout << "WagonR::Accele()\n"; }
};


int main()
{
    std::cout << "車を選択してください。" << "\n";
    int carNo = 0;
    std::cin >> carNo;

    Fit* fit = nullptr;
    Bits* bits = nullptr;
    WagonR* wagonR = nullptr;

    if (carNo == 0) {
        fit = new Fit();
    }
    else if (carNo == 1) {
        bits = new Bits();
    }
    else if (carNo == 2) {
        wagonR = new WagonR();
    }

    // ゲームループ
    while(true) {
        if (GetAsyncKeyState('A'))
        {
            // アクセルボタンを押された
            if (carNo == 0) {
                fit->Accele();
            }
            else if (carNo == 1) {
                bits->Accele();
            }
            else if (carNo == 2) {
                wagonR->Accele();
            }
        }

        if (GetAsyncKeyState('B'))
        {
            // ブレーキボタンを押された
            if (carNo == 0) {
                fit->Brake();
            }
            else if (carNo == 1) {
                bits->Brake();
            }
            else if (carNo == 2) {
                wagonR->Brake();
            }
        }
        // 移動させる処理を実行
        if (carNo == 0) {
            fit->Move();
        }
        else if (carNo == 1) {
            bits->Move();
        }
        else if (carNo == 2) {
            wagonR->Move();
        }

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
