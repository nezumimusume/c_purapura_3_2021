// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

//step-1 mapをインクルード
#include <map>

int main()
{
    // step-2 名前と年齢を記憶できる連想配列を定義する。

    // 名前と年齢を記憶できる連想配列を定義する。
    std::map< std::string, int > map;
    // 豊臣秀吉をキー、39を値にもつデータを挿入。
    map.insert( {"豊臣秀吉", 39} );
    // 織田信長、50歳を値に持つデータを挿入。
    map.insert( {"織田信長", 50} );

    
    // step-3 キーを使って要素にアクセスする。
    std::cout << map["豊臣秀吉"] << "\n"; // 39と表示される。
    std::cout << map["織田信長"] << "\n"; // 50と表示される。

    
    //step-4 for文を使って、mapに格納されているキーと値を表示する。
    for (
        std::map< std::string, int >::iterator it = map.begin();
        it != map.end();
        it++
        ) {
        // イテレーターはmapに格納されている要素を指しているの、std::pair型のオブジェクトを指しています。
        // なので、各要素のキーと値にアクセスすることができます。
        std::cout << "キーは" << it->first << "\n";
        std::cout << "値は" << it->second << "\n";
    }


    return 0;
}



