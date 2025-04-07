#include <iostream>
#include <random>
#include "Stopwatch.h"


void bubbleSort(int values[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // 1回のループで一番大きい値が右端に移動する
        for (int j = 0; j < size - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                // swap
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

int main()
{
    std::random_device seed_gen;
    std::mt19937 random(seed_gen());
    // データ数は1000万
    const int n = 10000000;
    static int values[n];
    for (int i = 0; i < n; i++) {
        values[i] = random() % n;
    }
    Stopwatch sw;
    sw.Start();
    // バブルソート
    bubbleSort(values, n);
    sw.Stop();

    std::cout << "ソートが完了しました。ソートにかかった時間は" << sw.GetElapsedMicrosecond() << "マイクロ秒です。\n";


    return 0;
}

