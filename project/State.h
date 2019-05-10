#pragma once

class GameCtrl;

class State
{
	friend class Context;
public:
	virtual ~State();
	virtual State &PressKeyBoard(const GameCtrl & controller) = 0;
	virtual void DrawString(void) = 0;
};

