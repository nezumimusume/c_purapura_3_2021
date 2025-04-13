#include <iostream>
#include <random>
#include "Stopwatch.h"


// マージ処理（2つの配列を1つにまとめる）
void merge(int values[], int left, int mid, int right, int L[], int R[]) {
    int n1 = mid - left + 1;  // 左半分のサイズ
    int n2 = right - mid;     // 右半分のサイズ

    // コピー
    for (int i = 0; i < n1; i++) L[i] = values[left + i];
    for (int i = 0; i < n2; i++) R[i] = values[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // 小さい順に詰め直す
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            values[k] = L[i];
            i++;
        }
        else {
            values[k] = R[j];
            j++;
        }
        k++;
    }

    // 残りを詰める
    while (i < n1) values[k++] = L[i++];
    while (j < n2) values[k++] = R[j++];
}

// マージソート本体（再帰）
void mergeSort(int values[], int left, int right, int tmpBuffer_00[], int tmpBuffer_01[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(values, left, mid, tmpBuffer_00, tmpBuffer_01);     // 左半分
        mergeSort(values, mid + 1, right, tmpBuffer_00, tmpBuffer_01); // 右半分

        merge(values, left, mid, right, tmpBuffer_00, tmpBuffer_01);   // マージ
    }
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::random_device seed_gen;
    std::mt19937 random(seed_gen());
    // データ数は1000万
    const int n = 10000000;
    static int values[n];
    static int workingBuffer_00[n/2];
    static int worrkingBuffer_01[n/2];
    for (int i = 0; i < n; i++) {
        values[i] = random() % n;
    }
    Stopwatch sw;
    sw.Start();
    // バブルソート
    mergeSort(values, 0, n-1, workingBuffer_00, worrkingBuffer_01);
    sw.Stop();

    std::cout << "ソートが完了しました。ソートにかかった時間は" << sw.GetElapsedMicrosecond() << "マイクロ秒です。\n";


    return 0;
}

