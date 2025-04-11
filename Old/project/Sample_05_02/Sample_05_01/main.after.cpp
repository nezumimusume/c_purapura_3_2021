// Sample_04_04.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>

// step-1 車のインターフェースクラスを実装する。
class ICarBase {
public:
    virtual void Move() = 0;
    virtual void Brake() = 0;
    virtual void Accele() = 0;
};

// step-2 ICarBaseを継承して各種クラスを定義する
class Fit : public ICarBase {
public:
    void Move(){ std::cout << "Fit::Move()\n"; }
    void Brake(){ std::cout << "Fit::Brake()\n"; }
    void Accele(){ std::cout << "Fit::Accele()\n"; }
};

class Bits : public ICarBase {
public:
    void Move(){ std::cout << "Bits::Move()\n"; }
    void Brake(){ std::cout << "Bits::Brake()\n"; }
    void Accele(){ std::cout << "Bits::Accele()\n"; }
};

class WagonR : public ICarBase {
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

    // step-3 各種車のインスタンスを生成する。
    ICarBase* selectCar = nullptr;

    if (carNo == 0) {
        selectCar = new Fit();
    }
    else if (carNo == 1) {
        selectCar = new Bits();
    }
    else if (carNo == 2) {
        selectCar = new WagonR();
    }

    // ゲームループ
    while(true) {
        // step-4 各種車のの処理を呼び出す。
        if (GetAsyncKeyState('A'))
        {
            // アクセルボタンを押された
            selectCar->Accele();
        }

        if (GetAsyncKeyState('B'))
        {
            // ブレーキボタンを押された
            selectCar->Brake();
        }
        // 移動させる処理を実行
        selectCar->Move();

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
