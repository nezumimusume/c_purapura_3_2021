// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
//step-1 listをインクルード
#include <list>

int main()
{
    //step-2 int型の要素を記録できる双方向リストを定義する。
    std::list<int> hoge;

    //step-3 hogeに要素を追加する
    hoge.push_back(10); //配列の末尾に10を追加する。
    hoge.push_back(20); //配列の末尾に20を追加する。
    hoge.push_back(30); //配列の末尾に30を追加する。

    //step-4 for文を使って、hogeの要素の値を表示する。
    
    for (
        std::list<int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
        ) {
        std::cout << *it << "\n";
    }

    return 0;
}



