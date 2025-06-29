#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

// コピー禁止機能を提供するクラス
class Noncopyable {
protected:
    Noncopyable() = default;
    ~Noncopyable() = default;
    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator=(const Noncopyable&) = delete;
};

class Hoge : Noncopyable{
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