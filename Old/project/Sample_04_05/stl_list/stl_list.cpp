// stl_vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>	//������C���N���[�h���邱�Ƃ�STL��list���g����悤�ɂȂ�B
#include <algorithm>

bool IsCompare(int value)
{
	if (value <= 20) {
		//20��菬����������폜�I
		return true;
	}
	return false;
}
int main()
{
	////////////////////////////////////////////////////////////////////
	//Chapter 1 �v�f�̒ǉ��B
	////////////////////////////////////////////////////////////////////
	std::list<int>  value;		//�o�������X�g�B�v�f�𓮓I�ɕύX���邱�Ƃ��ł���B
	value.push_back(10);		//�v�f�̒ǉ��B
	value.push_back(20);		//
	value.push_back(30);

	////////////////////////////////////////////////////////////////////
	//Chapter 2 �v�f�ւ̃A�N�Z�X�B
	////////////////////////////////////////////////////////////////////

	//2.1	for�����g����STL�̗v�f�ɃA�N�Z�X����B
	//
	//���X�g�͔z��ł͂Ȃ��̂Ń����_���A�N�Z�X�͂ł��Ȃ��I�I�I
	//std::list�ɂ�size�Ƃ��������o�ϐ�������B
	//����͌��݂̗v�f����Ԃ������o�ϐ��B
	for (int i = 0; i < value.size(); i++)
	{
	//	printf("%d\n", value[i]);		//
	}
	//2.1	�C�e���[�^�[���g����STL�̗v�f�ɃA�N�Z�X����B
	//
	//std::vector�ɂ͗v�f�ɃA�N�Z�X���邽�߂ɃC�e���[�^(�����q)�Ƃ������̂��g����B
	//����Ȋ����B
	std::list<int>::iterator it;
	//�|�C���^�̂悤�Ȋ����Ŏg����B
	for ( it = value.begin();		//���I�z��̍ŏ��̗v�f���珉�߂āA
		it != value.end();			//�I�[�ɂȂ�܂Ń��[�v���񂷁B
		it++
	) {
		printf("%d\n", *it);		//�܂�Ń|�C���^�̂悤�Ɉ�����B
	}
	
	//2.2	�^���_��foreach���g���ăA�N�Z�X����B
	// �����OKvector�Ɠ����悤�Ɉ�����B
	//
	//C++11�Ƃ���C++�̊g���d�l�Œǉ����ꂽ�@�\�B
	for (auto v : value) {
		printf("%d\n", v);
	}
	////////////////////////////////////////////////////////////////////
	//Chapter3 �v�f�̍폜�B
	//�������炿����Ɠ��
	//�����܂ł̓��e�ł�std::vector�͎g����̂ŁA���̐�͗����ł��Ȃ��Ă������̂Ŏg���Ċo���悤�I
	////////////////////////////////////////////////////////////////////
	//���I�z��͗v�f���폜���邱�Ƃ��ł���B
	//�v�f�̍폜��std::vector�̃����o�ϐ���erase���g���Ύ��s�ł���B
	//erase�ɍ폜�����C�e���[�^��n���΂����B
	//�Ȃ̂ŗႦ��10���폜�������ꍇ�͂���ȃR�[�h�������΂����H
#if 0
	for (
		it = value.begin();
		it != value.end();
		it++				//�c�O�Ȃ��炱���ŃN���b�V������������B�Ȃ��H
	) {
		if (*it == 10) {
			value.erase(it);		
		}
	}
#else
	//erase���ꂽ�C�e���[�^�͖����ɂȂ��Ă��܂��B
	//�����ɂȂ����C�e���[�^�ɑ΂���it++�����s���Ă��邽�߃N���b�V������������B
	//���႟�ǂ�����́H
	//��������B
	it = value.begin();
	while(it != value.end()) {
		if (*it == 10) {
			it = value.erase(it);		//erase�֐��͍폜���ꂽ�C�e���[�^�̎���Ԃ��Ă���̂ŁAerase�̖߂�l���g���B
		}
		else {
			it++;						//����ȊO�͎��ցB
		}
	}
#endif
	////////////////////////////////////////////////////////////////////
	//�������炳��ɓ���B
	////////////////////////////////////////////////////////////////////
	//���̍폜�̎d���͂܂�����������B
	//����ɔ��W�I�Ȃ��Ƃ�׋��������l�ցE�E�E�E
	//�v�f�̍폜��erase-remove�C�f�B�I�����g�����I�I�I
	//std::remove�͎��͍폜�͂��Ȃ��B�����Ƀ}�b�`����v�f�𖖔��Ɉړ������邾���B
	//�z���g�ɍ폜���邽�߂ɂ�erase���g���K�v������B
	//���ꂪerase-remove�C�f�B�I���B
	value.clear();
	printf("-----------------------\n");
	value.push_back(10);
	value.push_back(10);
	value.push_back(20);
	value.push_back(10);
	value.push_back(30);

	//std::remove(value.begin(), value.end(), 10);
	
	value.erase(
		std::remove(value.begin(), value.end(), 10),		
		value.end()
	);
	
	for (auto v : value) {
		printf("%d\n", v);
	}
	//����ȏ����ō폜�������ꍇ��std_remove_if���g���B
#if 0	
	//�֐��|�C���^���g���ŁB
	value.erase(
		std::remove_if(value.begin(), value.end(), IsCompare),
		value.end()
	);
#else	
	//�����_�����g���ŁB��i�I�ȃR�[�h�B
	//�֐��|�C���^�ł́A�֐��̖{�̂������ɂ���̂ŁA�R�[�h���ǂ݂Â炢�B
	//���ƁA���̎�̊֐��͑�R�o����̂ŁA���O���l����̂��߂�ǂ������B
	//�������I�����֐����g�����I�I�I
	auto func = [](int value)->bool {	//�����֐��B
		if (value <= 20) {
			//20��菬����������폜�I
			return true;
		}
		return false;
	};

	value.erase(
		std::remove_if(value.begin(), value.end(), func),
		value.end()
	);
#endif
	printf("----------------------------------\n");
	for (auto v : value) {
		printf("%d\n", v);
	}
    return 0;
}

