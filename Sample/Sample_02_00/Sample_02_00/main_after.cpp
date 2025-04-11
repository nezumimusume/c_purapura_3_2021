#include <iostream>
#include <random>
#include "Stopwatch.h"

// step-1 arrayをインクルードする
#include <array>

int main()
{
    // step-2 int型の要素数5のstd::arrayの変数を定義する
    std::array<int, 5> hoge;
    // step-3 hogeに値を代入する
    hoge[0] = 10;
    hoge[1] = 20;
    hoge[2] = 30;
    hoge[3] = 40;
    hoge[4] = 50;

    // step-4 hogeの値を表示する
    for (int i = 0; i < hoge.size(); i++) {
        std::cout << hoge[i] << "\n";
    }
    // step-5 最後に範囲外アクセスを起こして例外を起こしてみる。
    hoge[5] = 10;
    return 0;
}

