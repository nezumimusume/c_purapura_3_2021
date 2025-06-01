#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.reserve(7);
    
    std::cout << "vecのサイズは" << vec.size() << "です。\n";
    std::cout << "vecのキャパシティは" << vec.capacity() << "です。\n";
    return 0;
}