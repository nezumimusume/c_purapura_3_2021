#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

class Hoge {
public:
    std::string GetString() const {
        std::string localString = "ハローワールド";
        return localString;
    }
};


int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    Hoge hoge;
    std::cout << hoge.GetString();
    
    return 0;
} 