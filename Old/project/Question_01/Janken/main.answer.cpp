#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void DispPlayerNoTe(int player)
{
	//�@�v���C���[�̎��\��
	if (player == 0) {
		cout << "�v���C���[�̎�̓O�[�B\n";
	}
	else if (player == 1) {
		cout << "�v���C���[�̎�̓`���L�B\n";
	}
	//�����P player�̒l��2�̎����p�[�B
	//else if (player == 1) {
	else if (player == 2) {
		cout << "�v���C���[�̎�̓p�[�B\n";
	}
	
}
void DispComNoTe(int com)
{
	//�@COM�̎��\���B
	if (com == 0) {
		cout << "�R���s���[�^�̎�̓O�[�B\n";
	}
	else if (com == 1) {
		cout << "�R���s���[�^�̎�̓`���L�B\n";
	}
	else if (com == 2) {
		cout << "�R���s���[�^�̎�̓p�[�B\n";
	}
}
int main()
{
	//�@�������������B
	srand((unsigned)time(NULL));
	
	int battleCount = 0;	//�o�g���J�E���g�̏������B
	//�����Q�@�v���C���[�̏������̏����l�����������B
	//int playerWinCount = 10;	//�v���C���[�̏������B
	int playerWinCount = 0;	//�v���C���[�̏������B
	int comWinCount = 0;	//Com�̏������B
	int evenCount = 0;		//���������̉񐔁B

	//�@while�͏���������true�̊ԁA�������J��Ԃ��\���ł��B
	//�@���̂悤�Ȃ����Ɖ�郋�[�v���Q�[���ɂ͂����āA
	//�@���ꂪ�Q�[�����[�v�ƌĂ΂����̂ł��B�B

	while (true) {
		//�@COM�̎�������_���Ɍ���B
		int com = rand() % 3;	//0���O�[�A�P���`���L�A�Q���p�[�B

		//�@��������v���C���[�̎����͂�����B
		int player;
		cout << "******************�� " << battleCount + 1 << " ���*********************\n";
		cout << "���I��ł��������B0 : �O�[�A1�F�`���L�A2�F�p�[\n";
		cin >> player;

		//�@�v���C���[�̎��\���B
		DispPlayerNoTe(player);
		
		// �R���s���[�^�̎��\���B
		DispComNoTe(com);

		//�@player�Ƃ����ϐ��Ƀv���C���[�̎�Acom�Ƃ����ϐ��ɃR���s���[�^�̎�̏�񂪓����Ă���B
		//�@0���O�[�A�P���`���L�A�Q���p�[�ł��B
		if (( player == 0 && com == 1 )		//�@�v���C���[���O�[�A�R���s���[�^���`���L�B
			|| ( player == 1 && com == 2 )	//�@�v���C���[���`���L�A�R���s���[�^���p�[�B
			|| ( player == 2 && com == 0 )	//�@�v���C���[���p�[�A�R���s���[�^�[���O�[�B
		) {
			cout << "���Ȃ��̏����ł��B\n";
			playerWinCount++;
		}else if ((player == 1 && com == 0 ) 
			|| (player == 0 && com == 2)
			|| (player == 2 && com == 1 ) 
		){
			//�@�v���C���[���O�[�ACOM���p�[�B
			cout << "���Ȃ��̕����ł��B\n";
			comWinCount++;
		}
		else {
			cout << "���������ł��B\n";
			//�����R evenCount���C���N�������g����K�v������B
			//comWinCount++;
			evenCount++;
		}
		cout << "�� " << battleCount + 1 << " ���@�I��\n";
		cout << "��т�" << playerWinCount << "��" << comWinCount << "�s" << evenCount << "����" << "�ł��B\n";
		battleCount++;
	}
	
	return 0;
}