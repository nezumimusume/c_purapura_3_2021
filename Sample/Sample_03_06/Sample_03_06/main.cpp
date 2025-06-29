#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>


class Hoge{
private:
    int* bar = new int;
public:
    ~Hoge()
    {
        delete bar;
    }
};


int main() {
    Hoge hoge;
    // コピーが起きている
    Hoge hoge2 = hoge;
    
    return 0;
} 