#include <DxLib.h>
#include <memory>
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

uniqueState NotPress::PressKeyBoard(const GameCtrl & controller, uniqueState state)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);


	// スペースキーを押している状態
	if (ctrl[KEY_INPUT_SPACE])
	{
		return std::make_unique<PressSpace>();
	}

	// LSHIFTを押している状態
	if (ctrl[KEY_INPUT_LSHIFT])
	{
		return std::make_unique<PressLShift>();
	}

	// RSHIFTを押している状態
	if (ctrl[KEY_INPUT_RSHIFT])
	{
		return std::make_unique<PressRShift>();
	}

	return state;
}

void NotPress::DrawString(void)
{
	DrawFormatString(400, 200, 0x00ffffff, "ｎｏｔ Ｐｒｅｓｓ");
}
