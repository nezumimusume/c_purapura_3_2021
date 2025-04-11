// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <map>
#include <random>

int main()
{
    
    std::map< std::string, int > hoge;
    hoge.insert({ "豊臣秀吉", 30 });
    hoge.insert({ "織田信長", 40 });
    hoge.insert({ "武田信玄", 50 });

    // 課題-1 豊臣秀吉のデータをhogeから削除しなさい。
    
    




    // 答え合わせ
    {
        std::map< std::string, int >::iterator it;
        it = hoge.find("豊臣秀吉");
        if (it != hoge.end()) {
            std::cout << "削除できていない。不正解。\n";
        }
        else {
            std::cout << "正解。\n";
        }
    }
    

    return 0;
}



