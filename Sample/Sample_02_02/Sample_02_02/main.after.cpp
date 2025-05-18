// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <Windows.h>
#include <iostream>
//step-1 listをインクルード
#include <list>
//step-9 algorithmをインクルード
#include <algorithm>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //step-2 int型の要素を記録できる双方向リストを定義する
    std::list<int> hoge;

    //step-3 hogeに要素を追加する
    hoge.push_back(10); //配列の末尾に10を追加する。
    hoge.push_back(20); //配列の末尾に20を追加する。
    hoge.push_back(30); //配列の末尾に30を追加する。


    //step-4 hogeのサイズを表示する。
    std::cout << "hogeのサイズは" << hoge.size() << "です。\n";

    //step-5 for文を使って、hogeの要素の値を表示する。
    for(
        std::list<int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
    ){
        std::cout << "*itの値は" << *it << "です。\n";
    }

    //step-6 さらにhogeに要素を追加する
    hoge.push_back(40);
    hoge.push_back(50);

    //step-7 再度hogeのサイズを表示する
    std::cout << "hogeのサイズは" << hoge.size() << "です。\n";

    //step-8 もう一度for文を使って、hogeの要素の値を表示する
    for(
        std::list<int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
    ){
        std::cout << "*itの値は" << *it << "です。\n";
    }

    //step-10 指定した要素を削除する
    int target;
    std::cout << "削除したい数値を入力してください\n";
    std::cin >> target;
    // 削除する要素を指しているイテレーターを検索する
    // 今回はstd::findアルゴリズムを利用している
    std::list<int>::iterator itTarget = std::find(
        hoge.begin(),   // 検索するコンテナの先頭イテレーター
        hoge.end(), // 検索するコンテナの終端イテレータ
        target  // 検索する値
    );
    if(itTarget != hoge.end()){
        // 見つかった
        hoge.erase(itTarget);
    }
    // 削除後の要素を表示する
    for(
        std::list<int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
    ){
        std::cout << "*itの値は" << *it << "です。\n";
    }
    return 0;
}



