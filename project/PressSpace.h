#pragma once
#include "State.h"
#include "GameCtrl.h"

class PressSpace :
	public State
{
public:
	PressSpace();
	~PressSpace();

	uniqueState PressKeyBoard(const GameCtrl & controller, uniqueState state);
	void DrawString(void);
};

