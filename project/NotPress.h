#pragma once
#include "State.h"
#include "GameCtrl.h"

class NotPress :
	public State
{
public:
	NotPress();
	~NotPress();

	uniqueState PressKeyBoard(const GameCtrl & controller, uniqueState state) override;
	void DrawString(void) override;
};

