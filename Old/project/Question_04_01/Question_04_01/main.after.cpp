// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <array>
#include <map>

int main()
{

#if 1
    std::array< int, 10 > hoge = {
        10, 20, 30, 40
    };
    for (int i = 0; i < hoge.size(); i++) {
        std::cout << hoge[i] << "\n";
    }
    std::array<char, 256> hoge2;
    strcpy_s(hoge2.data(), hoge2.size(), "Hello world\n");
    std::cout << hoge2.data();
#else
    int hoge[10] = {
        10, 20, 30, 40
    };

    for (int i = 0; i < 10; i++) {
        std::cout << hoge[i] << "\n";
    }

    char hoge2[256];
    strcpy_s(hoge2, 256, "Hello world\n");
    std::cout << hoge2;
#endif
    return 0;
}



