#include <iostream>
#include <random>
#include "Stopwatch.h"


int binarySearch(int values[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // オーバーフロー対策

        if (values[mid] == target) {
            return mid;  // 見つかった！
        }
        else if (values[mid] < target) {
            left = mid + 1;  // 右側を探索
        }
        else {
            right = mid - 1; // 左側を探索
        }
    }

    return -1;  // 見つからない
}

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
    // バイナリサーチはソートされている必要があるのでソートする
    std::sort(values, values+n);

    // 検索する数値を入力させる
    std::cout << "検索したい数値を0～" << n-1 << "の範囲で入力してください。\n";
    int targetValue = 0;
    std::cin >> targetValue;
    targetValue = std::min<int>(std::max<int>(0, targetValue - 1), targetValue - 1);

    Stopwatch sw;
    sw.Start();
    // バイナリサーチを行う
    int index = binarySearch(values, n, targetValue);
    sw.Stop();
    if (index != -1) {
        // 何番目に見つかったかを表示する
        std::cout << targetValue << "番目見つかりました。検索にかかった時間は" << sw.GetElapsedMicrosecond() << "マイクロ秒です。\n";
    }
    else {
        std::cout << "見つかりませんでした。検索にかかった時間は" << sw.GetElapsedMicrosecond() << "マイクロ秒です。\n";
    }
    return 0;
}

