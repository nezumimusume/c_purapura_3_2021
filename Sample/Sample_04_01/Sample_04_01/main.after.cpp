#include <iostream>
#include <Windows.h>
#include <vector>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    std::cout << "Original values:\n";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\nModified values:\n";
    for (int& num : numbers) {
        num *= 2;
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
} 