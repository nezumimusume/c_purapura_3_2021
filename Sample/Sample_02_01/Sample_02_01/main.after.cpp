// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
//step-1 vectorをインクルード
#include <vector>

int main()
{
    //step-2 int型の要素を記録できる可変長配列を定義する。
    std::vector<int> hoge;

    //step-3 hogeに要素を追加する
    hoge.push_back(10); //配列の末尾に10を追加する。
    hoge.push_back(20); //配列の末尾に20を追加する。
    hoge.push_back(30); //配列の末尾に30を追加する。


    //step-4 hogeのサイズを表示する。
    std::cout << "hogeのサイズは" << hoge.size() << "です。\n";

    //step-5 for文を使って、hogeの要素の値を表示する。
    for (int i = 0; i < hoge.size(); i++) {
        std::cout 
            << "hoge["
            << i 
            << "]の値は" 
            << hoge[i] 
            << "です。\n";
    }

    //step-6 さらにhogeに要素を追加する。
    hoge.push_back(40);
    hoge.push_back(50);

    //step-7 再度hogeのサイズを表示する。
    std::cout << "hogeのサイズは" << hoge.size() << "です。\n";

    //step-8 もう一度for文を使って、hogeの要素の値を表示する。
    for (int i = 0; i < hoge.size(); i++) {
        std::cout
            << "hoge["
            << i
            << "]の値は"
            << hoge[i]
            << "です。\n";
    }

    return 0;
}



