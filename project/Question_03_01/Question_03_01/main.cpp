// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>


int main()
{
    std::vector< int > hoge;
    hoge.push_back(40);
    hoge.push_back(50);
    hoge.push_back(60);
    hoge.push_back(70);
    hoge.push_back(80);

    // 課題-1 
    // hogeから40、50、60の値を検索して、見つかったら
    // hogeから除去するプログラムを実装しなさい。
    




    // 答え合わせ
    bool isOk = true;
    for (
        std::vector< int >::iterator it = hoge.begin();
        it != hoge.end();
        it++
        ) {
        if (*it == 40 || *it == 50 || *it == 60) {
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



