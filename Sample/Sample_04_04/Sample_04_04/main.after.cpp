#include <iostream>
#include <Windows.h>
#include <vector>
#include <memory>

class Noncopyable {
protected:
    Noncopyable() = default;
    ~Noncopyable() = default;
    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator=(const Noncopyable&) = delete;
};

// コピー禁止
class Player : Noncopyable{
private:
	int m_hp = 100;
public:
    int GetHP() const
    {
        return m_hp;
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);

	std::vector<int> values;
	values.push_back(10);
	values.push_back(20);
    values.push_back(30);

    for(auto it = values.begin(); it != values.end(); it++){
        std::cout << *it << std::endl;
    }
    // std::make_uniqueを利用しているので型を推論できる
    auto value0 = std::make_unique<int>();
    *value0 = 10;
    // std::make_sharedを利用しているので型を推論できる
    auto value1 = std::make_shared<int>();
    // value1の型から推論できる
    auto value2 = value1;

    Player pl;
    // 元のコードと同じにするためにはconstと参照性を明示的に付与する必要がある。
    const auto& plref = pl;
    std::cout << "PlayerのHPは" << plref.GetHP() << std::endl;

	return 0;
}