#pragma once
#include <memory>

class GameCtrl;
class State;

using uniqueState = std::unique_ptr<State>;

class State
{
	friend class Context;
public:
	virtual ~State();
	virtual uniqueState PressKeyBoard(const GameCtrl & controller, uniqueState state) = 0;
	virtual void DrawString(void) = 0;
};

