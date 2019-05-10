#pragma once
#include "State.h"
#include "GameCtrl.h"

class Context
{
public:
	Context();
	~Context();

	void UpDate(const GameCtrl &  controller);
	void ChengeState(State state);
	void DrawString(void);
	const int GetState(void) const;

private:
	State state;
	int stateNum;
};

