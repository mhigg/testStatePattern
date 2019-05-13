#pragma once
#include "State.h"
#include "GameCtrl.h"

class PressLShift :
	public State
{
public:
	PressLShift();
	~PressLShift();

	uniqueState PressKeyBoard(const GameCtrl & controller, uniqueState state);
	void DrawString(void);
};

