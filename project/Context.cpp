#include <DxLib.h>
#include <memory>
#include "Context.h"
#include "GameCtrl.h"
#include "PressSpace.h"
#include "NotPress.h"
#include "PressLShift.h"
#include "PressRShift.h"


Context::Context()
{
	stateNum = 0;
	state = std::make_unique<NotPress>();
}


Context::~Context()
{
}

void Context::UpDate(const GameCtrl &  controller)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);


// -----------------------ステートパターンなし-----------------------

	stateNum = 2;

	// スペースキーを押している状態
	if (ctrl[KEY_INPUT_SPACE])
	{
		stateNum = 1;
	}

	// LSHIFTを押している状態
	if (ctrl[KEY_INPUT_LSHIFT])
	{
		stateNum = 3;
	}

	// RSHIFTを押している状態
	if (ctrl[KEY_INPUT_RSHIFT])
	{
		stateNum = 4;
	}

// -----------------------ステートパターンあり-----------------------

	state = state->PressKeyBoard(controller, std::move(state));

}

void Context::DrawString(void)
{
	state->DrawString();
}

const int Context::GetState(void) const
{
	return stateNum;
}
