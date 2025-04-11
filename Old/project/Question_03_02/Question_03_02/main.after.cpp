// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <random>

int main()
{
    std::random_device random;
    std::vector< int > hoge;

    for (int i = 0; i < 100000; i++) {
        // hogeにランダムで0～9の数値を記録する
        hoge.push_back(random() % 10);
    }
    
    // 課題-1 
    // hogeから5の値を全て除去するプログラムを実装しなさい。
    std::vector< int >::iterator it;
    it = std::find(hoge.begin(), hoge.end(), 5);
    while (it != hoge.end()) {
        hoge.erase( it );
        it = std::find( hoge.begin(), hoge.end(), 5 );
    }

    // 答え合わせ
    bool isOk = true;
    for (
        std::vector< int >::iterator it = hoge.begin();
        it != hoge.end();
        it++
        ) {
        if (*it == 5) {
            isOk = false;
            break;
        }
    }
    if (isOk) {
        std::cout << "正解\n";
    }
    else {
        std::cout << "不正解\n";
    }

    return 0;
}



