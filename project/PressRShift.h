#pragma once
#include "State.h"
class PressRShift :
	public State
{
public:
	static PressRShift & GetInstance(void)
	{
		static PressRShift s_instance;
		return s_instance;
	}

	void DrawString(void);

private:
	PressRShift();
	~PressRShift();
};

