#include <DxLib.h>
#include "SceneMng.h"


SceneMng::SceneMng()
{
	Init();
}

SceneMng::~SceneMng()
{
}

bool SceneMng::Init(void)
{
	// ¼½ÃÑˆ—
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536FÓ°ÄŞ‚Éİ’è
	ChangeWindowMode(true);				// true:window@false:ÌÙ½¸Ø°İ
	SetWindowText("StatePattern");
	if (DxLib_Init() == -1) return false;
	SetDrawScreen(DX_SCREEN_BACK);

	gameCtrl = std::make_unique<GameCtrl>();	//ÕÆ°¸Îß²İÀ
	context = std::make_unique<Context>();

	return true;
}

void SceneMng::UpDate(void)
{
	context->UpDate((*gameCtrl));

	Draw();
}

void SceneMng::Draw(void)
{
	std::string str;
	int state = context->GetState();

	ClsDrawScreen();

// -----------------------ƒXƒe[ƒgƒpƒ^[ƒ“‚È‚µ-----------------------

	switch (state)
	{
	case 1:
		str = "‚o‚’‚…‚“‚“ ‚r‚‚‚ƒ‚…";
		break;
	case 2:
		str = "‚‚‚” ‚o‚’‚…‚“‚“";
		break;
	case 3:
		str = "‚o‚’‚…‚“‚“ ‚k‚r‚g‚h‚e‚s";
		break;
	case 4:
		str = "‚o‚’‚…‚“‚“ ‚q‚r‚g‚h‚e‚s";
		break;
	default:
		str = "‚‚”‚ˆ‚…‚’";
		break;
	}

	DrawString(100, 200, str.c_str(), 0x00ff0000);

// -----------------------ƒXƒe[ƒgƒpƒ^[ƒ“‚ ‚è-----------------------

	context->DrawString();

	ScreenFlip();
}

void SceneMng::Run(void)
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameCtrl->UpDate();
		UpDate();
	}
}
