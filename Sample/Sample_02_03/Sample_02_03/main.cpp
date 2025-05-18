// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <Windows.h>
#include <iostream>
//step-1 mapをインクルード
#include <map>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //step-2 std::mapを定義する
    std::map<std::string, int> hoge;

    //step-3 hogeに要素を追加する
    //step-3 hogeに要素を追加する
    hoge.insert({"Alice", 90}); //Aliceのスコアを90にする
    hoge.insert({"Bob", 80}); //Bobのスコアを80にする
    hoge.insert({"Charlie", 70}); //Charlieのスコアを70にする

    //step-4 hogeのサイズを表示する。
    std::cout << "hogeのサイズは" << hoge.size() << "です。\n";

    //step-5 for文を使って、hogeの要素の値を表示する。
    //step-5 for文を使って、hogeの要素の値を表示する。
    for(
        std::map<std::string, int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
    ){
        std::cout << it->first << "のスコアは" << it->second << "です。\n";
    }
    //step-6 さらにhogeに要素を追加する
    hoge.insert({"David", 60}); //Davidのスコアを60にする
    hoge.insert({"Eve", 50}); //Eveのスコアを50にする

    //step-7 再度hogeのサイズを表示する
    std::cout << "hogeのサイズは" << hoge.size() << "です。\n";

    //step-8 もう一度for文を使って、hogeの要素の値を表示する
    for(
        std::map<std::string, int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
    ){
        std::cout << it->first << "のスコアは" << it->second << "です。\n";
    }

    //step-9 指定した要素を削除する
    std::string target;
    std::cout << "削除したい名前を入力してください\n";
    std::cin >> target;
    // std::map::find関数を利用して、指定した要素を検索する
    std::map<std::string, int>::iterator it = hoge.find(target);
    if (it != hoge.end()) {
        // 見つかったので削除。
        hoge.erase(it);
    }
    // 削除後の要素を表示する
    for(
        std::map<std::string, int>::iterator it = hoge.begin();
        it != hoge.end();
        it++
    ){
        std::cout << it->first << "のスコアは" << it->second << "です。\n";
    }
    
    return 0;
}



