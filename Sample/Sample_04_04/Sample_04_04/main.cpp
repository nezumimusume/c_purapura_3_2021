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

    for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++){
        std::cout << *it << std::endl;
    }

    std::unique_ptr<int> value0 = std::make_unique<int>();
    *value0 = 10;
    std::shared_ptr<int> value1 = std::make_shared<int>();
    std::shared_ptr<int> value2 = value1;

    Player pl;
    const Player& plref = pl;
    std::cout << "PlayerのHPは" << plref.GetHP() << std::endl;

	return 0;
}