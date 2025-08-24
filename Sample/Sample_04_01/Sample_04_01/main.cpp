#include <iostream>
#include <Windows.h>
#include <vector>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    std::cout << "変更前の値:\n";

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n\n変更後の値:\n";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        *it *= 2;
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
} 