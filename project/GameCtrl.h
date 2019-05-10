#pragma once
#include <array>

using KEY_ARY = std::array<char, 256>;

enum KEY_TYPE
{
	KEY_TYPE_NOW,	//���̷݂����
	KEY_TYPE_OLD,	//1�ڰёO�̏��
	KEY_TYPE_MAX
};

class GameCtrl
{
public:
	GameCtrl();
	~GameCtrl();
	const KEY_ARY &GetCtrl(KEY_TYPE type) const;	//�����擾�p�֐�
	bool UpDate(void);		//���̉�����Ԃ��擾,�X�V����

private:
	KEY_ARY keyData;	//���݂̉������
	KEY_ARY keyDataOld;	//1�ڰёO�̉������
};

