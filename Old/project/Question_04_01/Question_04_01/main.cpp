// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <array>
#include <map>

int main()
{
    int hoge[10] = {
        10, 20, 30, 40
    };

    for (int i = 0; i < 10; i++) {
        std::cout << hoge[i] << "\n";
    }

    char hoge2[256];
    strcpy_s(hoge2, 256, "Hello world\n");
    std::cout << hoge2;

    return 0;
}



