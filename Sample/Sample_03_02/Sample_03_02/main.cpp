#include <iostream>
#include <Windows.h>
#include <string>


// 継承することを前提とする基底クラス。
class GameObject {
private:
	std::string m_name;	// オブジェクトの名前を保持している。
public:
	// 引数付きのコンストラクタだけがある状態
	// -> かならず名前を指定してコンストラクトしてね
	GameObject(std::string name)
	{
	}
};

class Player : public GameObject{
public:
	Player(const std::string& name) : GameObject(name)
	{
	}
};
int main()
{
	Player pl_A("プレイヤーA");
	Player pl_B("プレイヤーB");
	Player pl_C("プレイヤーC");
	Player pl_D("プレイヤーD");
}