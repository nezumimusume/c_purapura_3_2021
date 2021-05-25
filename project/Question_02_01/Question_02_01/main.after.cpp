// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

// mapをインクルード
#include <map>

//　ユーザーアカウント構造体。
struct UserAccount {
    std::string userName;   //ユーザー名。
    int age;                     //年齢
    std::string dispName;   //表示名
};
int main()
{
    // ユーザーアカウントを記憶するための連想配列。
    std::map< std::string, UserAccount > userAccountMap;

    //　ユーザーアカウントを登録する。
    while (true) {
        std::cout << "新規ユーザーを登録しますか？ yes : 0、No : 1\n";
        int result;
        std::cin >> result;
        if ( result == 1 ){
            //新規ユーザー登録を辞める。
            break;
        }
        // 新規ユーザーアカウント情報の入力を求める。
        UserAccount userAccount;
        std::cout << "ユーザー名を入力してください。\n";
        std::cin >> userAccount.userName;
        std::cout << "年齢を入力してください。\n";
        std::cin >> userAccount.age;
        std::cout << "表示名を入力してください。\n";
        std::cin >> userAccount.dispName;

        // 課題-1 ユーザー名をキー、ユーザーアカウント情報を値にして、userAccountMapに挿入する。
        userAccountMap.insert({ userAccount.userName, userAccount });

    }
    std::cout << "登録されているユーザ情報を表示します。" << "\n";
    // 課題-2 for文を利用して、登録済みのユーザー情報をすべて表示する。
    for (
        std::map< std::string, UserAccount >::iterator it = userAccountMap.begin();
        it != userAccountMap.end();
        it++
        ) {
        std::cout << "ユーザー名 : " << it->first << "\n";
        std::cout << "年齢 : " << it->second.age << "\n";;
        std::cout << "表示名 : " << it->second.dispName << "\n";;
    }

    //ユーザー検索
    while (true) {
        std::cout << "ユーザーを検索しますか？ yes:0、No:1\n";
        int result;
        std::cin >> result;
        if (result == 1) {
            //ユーザー検索終わり。
            break;
        }
        //　ユーザー名を入力させる。
        std::cout << "ユーザー名を入力してください。\n";
        std::string userName;
        std::cin >> userName;

        // ユーザーが登録されているかを調べる。
        std::map< std::string, UserAccount >::iterator it;
        //　指定された名前のユーザーを連想配列から検索。
        it = userAccountMap.find(userName);

        if (it != userAccountMap.end()) {
            // itが終端でなければ、見つかっているので表示する。
            // 課題-3 見つかったユーザー情報をすべて表示する。
            std::cout << "ユーザー名 : " << it->first << "\n";
            std::cout << "年齢 : " << it->second.age << "\n";;
            std::cout << "表示名 : " << it->second.dispName << "\n";;
        }
        else {
            // 見つからなかった。
            std::cout << "指定されたユーザーは存在していません。\n";
        }

    }

    return 0;
}



