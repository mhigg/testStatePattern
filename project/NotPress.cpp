#include <DxLib.h>
#include "NotPress.h"
#include "PressSpace.h"
#include "PressLShift.h"
#include "PressRShift.h"



NotPress::NotPress()
{
}


NotPress::~NotPress()
{
}

State & NotPress::PressKeyBoard(const GameCtrl & controller)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);


	// スペースキーを押している状態
	if (ctrl[KEY_INPUT_SPACE])
	{
		State::ChengeState(PressSpace::GetInstance());
	}

	// LSHIFTを押している状態
	if (ctrl[KEY_INPUT_LSHIFT])
	{
		ChengeState(PressLShift::GetInstance());
	}

	// RSHIFTを押している状態
	if (ctrl[KEY_INPUT_RSHIFT])
	{
		ChengeState(PressRShift::GetInstance());
	}

	return ;
}

void NotPress::DrawString(void)
{
	DrawFormatString(400, 200, 0x00ffffff, "ｎｏｔ Ｐｒｅｓｓ");
}
