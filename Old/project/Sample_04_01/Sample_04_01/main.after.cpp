// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

// step-1 MyArrayクラスを作成する。
template <class T, int SIZE >
class MyArray {
    T value[SIZE];
public:
    T& operator[](int index)
    {
    //これは条件付きコンパイル機能。_DEBUGというシンボルが定義されている場合に#ifdef～#elseのコードがコンパイルされる。
#ifdef _DEBUG 
        if (index < SIZE) {
            return value[index];
        }
        else {
            std::abort();
        }
#else
    //こっち側は_DEBUGが定義されていない場合にコンパイルされる。
        return value[index];
#endif
    }
    
};


int main()
{
    // step-2 MyArrayクラスを使ってみる。
    MyArray< int, 10 > hoge;
    hoge[0] = 10;
    std::cout << hoge[0];
    // デバッグビルドではここでクラッシュする！
    hoge[10] = 20;
    return 0;
}



