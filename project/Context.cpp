#include <DxLib.h>
#include "Context.h"
#include "GameCtrl.h"
#include "PressSpace.h"
#include "NotPress.h"
#include "PressLShift.h"
#include "PressRShift.h"



Context::Context()
{
	stateNum = 0;
	state = NotPress::GetInstance();
}


Context::~Context()
{
}

void Context::UpDate(const GameCtrl &  controller)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);


// -----------------------�X�e�[�g�p�^�[���Ȃ�-----------------------

	stateNum = 2;

	// �X�y�[�X�L�[�������Ă�����
	if (ctrl[KEY_INPUT_SPACE])
	{
		stateNum = 1;
	}

	// LSHIFT�������Ă�����
	if (ctrl[KEY_INPUT_LSHIFT])
	{
		stateNum = 3;
	}

	// RSHIFT�������Ă�����
	if (ctrl[KEY_INPUT_RSHIFT])
	{
		stateNum = 4;
	}

// -----------------------�X�e�[�g�p�^�[������-----------------------

	state.PressKeyBoard(controller);

}

void Context::ChengeState(State state)
{
	this->state = state;
}

void Context::DrawString(void)
{
	state.DrawString();
}

const int Context::GetState(void) const
{
	return stateNum;
}
