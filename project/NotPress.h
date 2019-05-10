#pragma once
#include "State.h"
#include "GameCtrl.h"

class NotPress :
	public State
{
public:
	static NotPress & GetInstance(void)
	{
		static NotPress s_instance;
		return s_instance;
	}

	State &PressKeyBoard(const GameCtrl & controller) override;
	void DrawString(void) override;

private:
	NotPress();
	~NotPress();
};

