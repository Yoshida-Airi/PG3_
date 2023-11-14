#pragma once
#include"Novice.h"
#include"InputManager.h"

#include<memory>
#include"Scene/IScene.h"
#include"Scene/TitleScene.h"
#include"Scene/ClearScene.h"
#include"Scene/StageScene.h"

class GameManager 
{
public:
	GameManager();
	~GameManager();

	int Run();

private:
	InputManager* inputManager;
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

};
