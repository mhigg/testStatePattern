#include <DxLib.h>
#include <memory>
#include "PressRShift.h"
#include "PressSpace.h"
#include "NotPress.h"
#include "PressLShift.h"


PressRShift::PressRShift()
{
}


PressRShift::~PressRShift()
{
}

uniqueState PressRShift::PressKeyBoard(const GameCtrl & controller, uniqueState state)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);


	// ƒXƒy[ƒXƒL[‚ğ‰Ÿ‚µ‚Ä‚¢‚éó‘Ô
	if (ctrl[KEY_INPUT_SPACE])
	{
		return std::make_unique<PressSpace>();
	}

	// LSHIFT‚ğ‰Ÿ‚µ‚Ä‚¢‚éó‘Ô
	if (ctrl[KEY_INPUT_LSHIFT])
	{
		return std::make_unique<PressLShift>();
	}

	// RSHIFT‚ğ‰Ÿ‚µ‚Ä‚¢‚È‚¢ó‘Ô
	if (!ctrl[KEY_INPUT_RSHIFT])
	{
		return std::make_unique<NotPress>();
	}

	return state;
}

void PressRShift::DrawString(void)
{
	DrawFormatString(400, 200, 0x000000ff, "‚o‚’‚…‚“‚“ ‚q‚r‚g‚h‚e‚s");
}
