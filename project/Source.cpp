using namespace std;
#include <stdlib.h>
#include <Dxlib.h>	// DxLibﾗｲﾌﾞﾗﾘを使用する
#include "SceneMng.h"


// ---------- WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	lpSceneMng.Run();

	DxLib_End();	// DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;
}
