#pragma once
// クラス宣言。
class Test
{
public:
	// コンストラクタ。
	Test();
	// デストラクタ。
	~Test();
	// Move関数。
	void Mobe();
	// 更新関数
	void Update(int deltaTime);
private:
	int m_moveSpeed = 0; // 移動速度。
};

