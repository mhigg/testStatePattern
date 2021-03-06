#include <DxLib.h>
#include <memory>
#include "PressLShift.h"
#include "PressSpace.h"
#include "NotPress.h"
#include "PressRShift.h"


PressLShift::PressLShift()
{
}


PressLShift::~PressLShift()
{
}

uniqueState PressLShift::PressKeyBoard(const GameCtrl & controller, uniqueState state)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);


	// スペースキーを押している状態
	if (ctrl[KEY_INPUT_SPACE])
	{
		return std::make_unique<PressSpace>();
	}

	// RSHIFTを押している状態
	if (ctrl[KEY_INPUT_RSHIFT])
	{
		return std::make_unique<PressRShift>();
	}

	// LSHIFTを押していない状態
	if (!ctrl[KEY_INPUT_LSHIFT])
	{
		return std::make_unique<NotPress>();
	}

	return state;
}

void PressLShift::DrawString(void)
{
	DrawFormatString(400, 200, 0x0000ff00, "Ｐｒｅｓｓ ＬＳＨＩＦＴ");
}
