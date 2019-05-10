#pragma once
#include <memory>
#include "GameCtrl.h"
#include "Context.h"

constexpr int SCREEN_SIZE_X = 800;
constexpr int SCREEN_SIZE_Y = 600;

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{

public:
	static SceneMng & GetInstance(void)
	{
		static SceneMng s_instance;
		return s_instance;
	}

	void Run(void);

private:
	SceneMng();
	~SceneMng();

	bool Init(void);
	void UpDate(void);
	void Draw(void);

	std::unique_ptr<GameCtrl> gameCtrl;
	std::unique_ptr<Context> context;
};

