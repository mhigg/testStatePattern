#pragma once
// ﾌﾟﾚｲﾔｰに位置するｸﾗｽ

#include "State.h"
#include "GameCtrl.h"

class Context
{
public:
	Context();
	~Context();

	void UpDate(const GameCtrl & controller);	// SetMoveに位置する関数
	void DrawString(void);
	const int GetState(void) const;

private:
	uniqueState state;  // 自身の状態
	int stateNum;
};

