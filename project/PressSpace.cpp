#include <DxLib.h>
#include <memory>
#include "PressSpace.h"
#include "NotPress.h"
#include "PressLShift.h"
#include "PressRShift.h"


PressSpace::PressSpace()
{
}


PressSpace::~PressSpace()
{
}

uniqueState PressSpace::PressKeyBoard(const GameCtrl & controller, uniqueState state)
{
	auto ctrl = controller.GetCtrl(KEY_TYPE_NOW);
	auto ctrlOld = controller.GetCtrl(KEY_TYPE_OLD);



	// LSHIFT�������Ă�����
	if (ctrl[KEY_INPUT_LSHIFT])
	{
		return std::make_unique<PressLShift>();
	}

	// RSHIFT�������Ă�����
	if (ctrl[KEY_INPUT_RSHIFT])
	{
		return std::make_unique<PressRShift>();
	}

	// �X�y�[�X�L�[�������Ă��Ȃ����
	if (!ctrl[KEY_INPUT_SPACE])
	{
		return std::make_unique<NotPress>();
	}

	return state;
}

void PressSpace::DrawString(void)
{
	DrawFormatString(400, 200, 0x00ff0000, "�o�������� �r��������");
}
