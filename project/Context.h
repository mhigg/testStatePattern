#pragma once
// ��ڲ԰�Ɉʒu����׽

#include "State.h"
#include "GameCtrl.h"

class Context
{
public:
	Context();
	~Context();

	void UpDate(const GameCtrl & controller);	// SetMove�Ɉʒu����֐�
	void DrawString(void);
	const int GetState(void) const;

private:
	uniqueState state;  // ���g�̏��
	int stateNum;
};

