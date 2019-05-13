#pragma once
// ÌßÚ²Ô°‚ÉˆÊ’u‚·‚é¸×½

#include "State.h"
#include "GameCtrl.h"

class Context
{
public:
	Context();
	~Context();

	void UpDate(const GameCtrl & controller);	// SetMove‚ÉˆÊ’u‚·‚éŠÖ”
	void DrawString(void);
	const int GetState(void) const;

private:
	uniqueState state;  // ©g‚Ìó‘Ô
	int stateNum;
};

