#pragma once
#include "State.h"
#include "GameCtrl.h"

class PressRShift :
	public State
{
public:
	PressRShift();
	~PressRShift();

	uniqueState PressKeyBoard(const GameCtrl & controller, uniqueState state);
	void DrawString(void);
};

