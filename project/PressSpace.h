#pragma once
#include "State.h"
class PressSpace :
	public State
{
public:
	static PressSpace & GetInstance(void)
	{
		static PressSpace s_instance;
		return s_instance;
	}

	void DrawString(void);

private:
	PressSpace();
	~PressSpace();
};

