#pragma once
// �N���X�錾�B
class Test
{
public:
	// �R���X�g���N�^�B
	Test();
	// �f�X�g���N�^�B
	~Test();
	// Move�֐��B
	void Mobe();
	// �X�V�֐�
	void Update(int deltaTime);
private:
	int m_moveSpeed = 0; // �ړ����x�B
};

