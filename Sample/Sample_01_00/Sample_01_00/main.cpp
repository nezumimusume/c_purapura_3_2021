#include <iostream>
#include <random>
#include "Stopwatch.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    std::random_device seed_gen;
    std::mt19937 random(seed_gen());
    // データ数は1000万
    const int n = 10000000;
    static int values[n];
    for (int i = 0; i < n; i++) {
        values[i] = random() % n;
    }

    // 検索する数値もランダムに決定する
    std::cout << "検索したい数値を0～" << n-1 << "の範囲で入力してください。\n";
    int targetIndex = 0;
    std::cin >> targetIndex;
    targetIndex = std::min<int>(std::max<int>(0, targetIndex - 1), targetIndex - 1);

    Stopwatch sw;
    sw.Start();
    bool find = false;
    // 全検索
    for (int i = 0; i < n; i++) {
        if (values[i] == 0) {
            targetIndex = i;
            find = true;
            break;
        }
    }
    sw.Stop();
    if (find) {
        // 何番目に見つかったかを表示する
        std::cout << targetIndex << "番目見つかりました。検索にかかった時間は" << sw.GetElapsedMicrosecond() << "マイクロ秒です。\n";
    }
    else {
        std::cout << "見つかりませんでした。検索にかかった時間は" << sw.GetElapsedMicrosecond() << "ミリ秒です。\n";
    }
    return 0;
}

