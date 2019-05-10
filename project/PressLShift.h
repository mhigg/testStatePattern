#pragma once
#include "State.h"
class PressLShift :
	public State
{
public:
	static PressLShift & GetInstance(void)
	{
		static PressLShift s_instance;
		return s_instance;
	}

	void DrawString(void);

private:
	PressLShift();
	~PressLShift();
};

